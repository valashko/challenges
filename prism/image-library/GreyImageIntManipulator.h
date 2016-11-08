#pragma once

#include <cassert>
#include <vector>

#include "ImageManipulator.h"


namespace Prism
{
class GreyImageIntManipulator final : public ImageManipulator
{
public:
  using StoredPixelType = int;

  GreyImageIntManipulator(const unsigned int width,
                          const unsigned int height,
                          const std::vector< StoredPixelType > & data):
      width_(width),
      height_(height),
      data_(data)
  {
    assert(width * height == data.size()); // TODO replace with exception
  }

private:
  virtual unsigned int getWidth() const override
  {
    return width_;
  }

  virtual unsigned int getHeight() const override
  {
    return height_;
  }

  virtual Pixel doGet(const unsigned int x, const unsigned int y) const override
  {
    // TODO assert coordinates since they have been checked by base class
    return data_[width_ * y + x];
  }

  virtual void doSet(const unsigned int x, const unsigned int y, const Pixel & value) override
  {
    // TODO assert coordinates since they have been checked by base class
    data_[width_ * y + x] = value.cast< StoredPixelType >(); // copy the value
  }


  unsigned int width_;
  unsigned int height_;
  std::vector< StoredPixelType > data_;
};
}

