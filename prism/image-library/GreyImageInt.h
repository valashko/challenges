#pragma once

#include <vector>

#include "GreyImageIntManipulator.h"
#include "Image.h"


namespace Prism
{
class GreyImageInt : public Image
{
public:
  GreyImageInt(const unsigned int width,
               const unsigned int height,
               const std::vector< GreyPixelInt > data):
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


  GreyImageIntManipulator manipulator_;
};
}

