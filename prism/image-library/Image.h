#pragma once

#include <memory>

#include "ImageManipulator.h"
#include "Pixel.h"


namespace Prism
{
// this class has several implementations depending on pixel depth and type
// currently the selection is done by calling a constructor of the appropriate class
// TODO concrete class to be selected via factory
class Image
{
public:
  // methods below are forwarded using NVI
  unsigned int width() const { return getManipulator().width(); }
  
  unsigned int height() const { return getManipulator().height(); }
  
  Pixel get(const unsigned int x, const unsigned int y) const
  {
    return getManipulator().get(x, y);
  }
  void set(const unsigned int x, const unsigned int y, const Pixel & value)
  {
    getManipulator().set(x, y, value);
  }

  // TODO implement methods through the same mechanism as the rest above
  // std::unique_ptr< Image > copy() const { return getManipulator().copy(); }
  // void convolve(const Kernel3x3 & kernel) { getManipulator().convolve(kernel); }
  // void scale(const unsigned int factor) { getManipulator().scale(factor); }

  virtual ~Image() { }

  // FIXME decide what to do with compiler-generated methods:
  // ctor, copy ctor, move ctor, assignment, move assignment

private:
  // TODO separate different aspects: scaling, actual data storage etc.
  // and provide getters for implementations in a similar way as getManipulator():
  // getScaler() -> implements scale()
  // getPixelStorage() -> implements data access
  // get***

  // FIXME potential pitfall: somebody may accidentally replace the manipulator through this call
  virtual Prism::ImageManipulator & getManipulator() = 0; // this is essentially PIMPL
  virtual const Prism::ImageManipulator & getManipulator() const = 0;
};
}

