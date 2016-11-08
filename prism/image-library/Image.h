#pragma once

#include <memory>

#include "ImageManipulator.h"


namespace Prism
{
class Image
{
public:
  unsigned int width() const { return getManipulator().width(); } // method forwarding using NVI
  unsigned int height() const { return getManipulator().height(); } // method forwarding using NVI
 
  virtual ~Image() { }

private:
  // TODO separate different aspects: scaling, actual pixel storage etc.
  // and provide getters for implementation in a similar way as getManipulator():
  // getScaler() -> implements scale()
  // getPixelStorage() -> implements pixel access
  // get***

  // FIXME potential pitfall: somebody may accidentally replace the manipulator through this call
  virtual Prism::ImageManipulator & getManipulator() = 0; // this is essentially PIMPL
  virtual const Prism::ImageManipulator & getManipulator() const = 0;
};
}

