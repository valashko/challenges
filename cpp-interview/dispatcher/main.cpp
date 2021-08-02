#include <chrono>
#include <future>
#include <iostream>
#include <type_traits>

#include "Application.h"

using namespace std::chrono_literals;
using std::cout;

class SmartApplication final : public Application {
public:
  template <typename Callable>
  std::future<std::invoke_result_t<Callable>>
  executeOnMainThread(Callable &&f) {
    // write some code here
  }

protected:
  void process(Event *const) override {
    // write some code here
  }
};

int main(int argc, const char *argv[]) {
  SmartApplication app;

  std::thread sequenceGenerator{[&] {
    for (auto i = 0; i < 100; ++i) {
      auto result = app.executeOnMainThread([=] {
        std::this_thread::sleep_for(1s);
        return i;
      });
      cout << "this is " << result.get() << "\n";
    }
  }};

  std::thread backwardsSequenceGenerator{[&] {
    for (auto i = 100; i > 0; --i) {
      auto result = app.executeOnMainThread([=] {
        std::this_thread::sleep_for(2s);
        return i;
      });
      cout << result.get() << " is this\n";
    }
  }};

  app.run();
  return 0;
}
