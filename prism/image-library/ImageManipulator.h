#pragma once


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

  virtual ~ImageManipulator() { }

private:
  virtual unsigned int getWidth() const = 0;
  virtual unsigned int getHeight() const = 0;
};
}

