#pragma once

namespace SimpleMath
{
  struct Point
  {
    Point(const double ax, const double ay):
        x(ax),
        y(ay)
    { }

    // TODO maybe unused
    const double distanceTo(const Point & other) {
      return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }

    const double x;
    const double y;
  };

  struct Vector
  {
    Vector(const double x, const double y):
        Vector(Point(x, y))
    { }

    explicit Vector(const Point & p):
        representation(p),
        x(representation.x),
        y(representation.y)
    { }

    const Vector orthogonal() const {
      return Vector(y, -x);
    }

    const Point representation;
    const double & x; // TODO prettify
    const double & y; // TODO prettify
  };

  const Vector operator-(const Vector & v) {
    return Vector(-v.x, -v.y);
  }

  const Vector operator+(const Vector & lhs, const Vector & rhs) {
    return Vector(lhs.x + rhs.x, lhs.y + lhs.y);
  }

  const Vector operator-(const Vector & lhs, const Vector & rhs) {
    return lhs + (-rhs);
  }

  double operator*(const Vector & lhs, const Vector & rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
  }

  double crossProductMagnitude(const Vector & lhs, const Vector & rhs) {
    return std::abs(lhs.x * rhs.y - lhs.y * rhs.x);
  }

  struct Ray
  {
    Ray(const Point & aOrigin, const Vector & aDirection):
        origin(aOrigin),
        direction(aDirection)
   { }

   const Point origin;
   const Vector direction;
  };

  struct Segment
  {
    Segment(const Point & aStart, const Point & aEnd):
        start(aStart),
        end(aEnd)
    { }

    const Point start;
    const Point end;
  };

};

