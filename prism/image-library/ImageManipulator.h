#pragma once

#include "Pixel.h"


namespace Prism
{
// this class combines all the aspects of processing an image
// given more time I would separate them into different enities
class ImageManipulator
{
public:
  unsigned int width() const // method forwarding using NVI
  {
    return getWidth();
  }

  unsigned int height() const // method forwarding using NVI
  {
    return getHeight();
  }

  Pixel get(const unsigned int x, const unsigned int y) const
  {
    // TODO check coordinates and throw
    return doGet(x, y);
  }

  void set(const unsigned int x, const unsigned int y, const Pixel & value)
  {
    // TODO check coordinates and throw
    doSet(x, y, value);
  }
  
  virtual ~ImageManipulator() { }

private:
  virtual unsigned int getWidth() const = 0;
  virtual unsigned int getHeight() const = 0;
  virtual Pixel doGet(const unsigned int x, const unsigned int y) const = 0;
  virtual void doSet(const unsigned int x, const unsigned int y, const Pixel & value) = 0;
};
}

