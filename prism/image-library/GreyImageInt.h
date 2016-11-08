#pragma once

#include <vector>

#include "GreyImageIntManipulator.h"
#include "Image.h"


namespace Prism
{
class GreyImageInt : public Image
{
public:
  using ManipulatorType = GreyImageIntManipulator;

  GreyImageInt(const unsigned int width,
               const unsigned int height,
               const std::vector< ManipulatorType::StoredPixelType > data):
      manipulator_(width, height, data)
  { }

  virtual ~GreyImageInt() { }

private:
  virtual Prism::ImageManipulator & getManipulator() override
  {
    return manipulator_;
  }

  virtual const Prism::ImageManipulator & getManipulator() const override
  {
    return manipulator_;
  }


  ManipulatorType manipulator_;
};
}

