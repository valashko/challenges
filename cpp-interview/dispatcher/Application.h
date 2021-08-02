#pragma once

#include <atomic>
#include <chrono>
#include <queue>
#include <thread>
#include <utility>

#include "Event.h"

class Application {
public:
  void dispatchEvent(std::unique_ptr<Event> event) {
    std::lock_guard<decltype(queueSync_)> lock{queueSync_};
    pendingEvents_.push(std::move(event));
  }

  void run() {
    isRunning_ = true;
    auto main = std::thread{[&] {
      while (isRunning_) {
        {
          std::unique_lock<decltype(queueSync_)> lock{queueSync_};
          if (!pendingEvents_.empty()) {
            auto event = pendingEvents_.front().get();
            lock.unlock();
            process(event);
            lock.lock();
            pendingEvents_.pop();
          }
        }
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(32ms);
      }
    }};
    main.join();
  }
  void quit() { isRunning_ = false; }

protected:
  virtual void process(Event *const) = 0;
  ~Application() = default;

private:
  std::atomic<bool> isRunning_;
  std::mutex queueSync_;
  std::queue<std::unique_ptr<Event>> pendingEvents_;
};
