#include <iostream>
#include <stdexcept>
#include <string>

#include "GreyImageInt.h"
using namespace Prism;


int main()
{
  std::vector< int > greyPixels = { 0, 1, 2, 3, 4 };
  const Image & greyImage = GreyImageInt(5, 1, greyPixels);
  std::cout << "w: " << greyImage.width() << ", h: " << greyImage.height() << std::endl;
  std::cout << "get(4,0) = " << greyImage.get(4, 0).cast< int >() << std::endl;

  return 0;
}

