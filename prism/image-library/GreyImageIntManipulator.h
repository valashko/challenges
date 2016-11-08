#pragma once

#include <cassert>
#include <vector>

#include "GreyPixelInt.h"
#include "ImageManipulator.h"


namespace Prism
{
class GreyImageIntManipulator final : public ImageManipulator
{
public:
  GreyImageIntManipulator(const unsigned int width,
                          const unsigned int height,
                          const std::vector< GreyPixelInt > & data):
      width_(width),
      height_(height),
      data_(data)
  {
    assert(width * height == data.size()); // TODO replace with exception
  }

private:
  virtual unsigned int getWidth() const
  {
    return width_;
  }

  virtual unsigned int getHeight() const
  {
    return height_;
  }

  unsigned int width_;
  unsigned int height_;
  std::vector< GreyPixelInt > data_;
};
}

