#include <cmath>
#include <cassert>
#include <iostream>

#include "simplemath.h"

using std::cout;
using namespace SimpleMath;

/*
** see this link for details:
** https://rootllama.wordpress.com/2014/06/20/ray-line-segment-intersection-test-in-2d/
*/
namespace IntersectionTest
{
  struct RaySegmentIntersectionParameters
  {
    RaySegmentIntersectionParameters(const double at1, const double at2):
        t1(at1),
        t2(at2)
    { }

    const double t1;
    const double t2;
  };

#if 0 // OLD
  const RaySegmentIntersectionParameters calculateRaySegmentIntersection(
      const Ray & ray, const Segment & segment) {
    const Vector & v1 = Vector(ray.origin) - Vector(segment.start);
    const Vector & v2 = Vector(segment.end) - Vector(segment.start);
    const Vector & v3 = Vector(-ray.direction.y, ray.direction.x);
    assert(v2 * v3 != 0); // TODO collinear
    const double t1 = crossProductMagnitude(v2, v1) / (v2 * v3);
    const double t2 = (v1 * v3) / (v2 * v3);
    return RaySegmentIntersectionParameters(t1, t2);
  }
#else
  const RaySegmentIntersectionParameters calculateRaySegmentIntersection(
      const Ray & ray, const Segment & segment) {
    const Vector & p0 = Vector(ray.origin);
    const Vector & d0 = ray.direction;
    const Vector & p1 = Vector(segment.start);
    const Vector & d1 = Vector(segment.end) - Vector(segment.start);
    const Vector & v3 = Vector(-ray.direction.y, ray.direction.x);
    const double denominator = (d1.orthogonal() * d0);// TODO rename this
    assert(denominator != 0); // TODO collinear
    const double t1 = (d1.orthogonal() * (p1-p0)) / denominator;
    const double t2 = (d0.orthogonal() * (p1-p0)) / denominator;
    return RaySegmentIntersectionParameters(t1, t2);
  }
#endif

  bool raySegmentAreIntersecting(const Ray & ray, const Segment & segment) {
    const auto par = calculateRaySegmentIntersection(ray, segment);
    cout << "DBG: t1=" << par.t1 << ", t2=" << par.t2 << "\n";
    return (par.t1 >= 0) && (par.t2 >= 0) && (par.t2 <= 1);
  }
};


int main()
{
  const Ray r1 = Ray(Point(0,0),Vector(1/std::sqrt(2),1/std::sqrt(2)));
  const Ray r2 = Ray(Point(4,4),Vector(1,1));
  const Ray r3 = Ray(Point(6,6),Vector(1,1));

  const Segment s1 = Segment(Point(4,2),Point(4,6));
  const Segment s2 = Segment(Point(5,2),Point(6,5));

  cout << "r1 | s1 = " << IntersectionTest::raySegmentAreIntersecting(r1, s1) << "\n";
  cout << "r1 | s2 = " << IntersectionTest::raySegmentAreIntersecting(r1, s2) << "\n";
  cout << "r2 | s1 = " << IntersectionTest::raySegmentAreIntersecting(r2, s1) << "\n";
  cout << "r2 | s2 = " << IntersectionTest::raySegmentAreIntersecting(r2, s2) << "\n";
  cout << "r3 | s1 = " << IntersectionTest::raySegmentAreIntersecting(r3, s1) << "\n";
  cout << "r3 | s2 = " << IntersectionTest::raySegmentAreIntersecting(r3, s2) << "\n";

  // TODO parallel seem to intersect

  return 0;
}

