#pragma once

class Event {
public:
  using Tag = int;
  Event(Tag tag) : tag_{tag} {}
  Tag tag() const { return tag_; }
  virtual ~Event() = default;
private:
  Tag tag_;
};
