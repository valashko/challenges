#include <iostream>
#include <stdexcept>
#include <string>

#include "GreyImageInt.h"
#include "GreyPixelInt.h"
using namespace Prism;


int main()
{
  const Image & greyImage = GreyImageInt(16, 9, std::vector< GreyPixelInt >(16*9));
  std::cout << "w: " << greyImage.width() << ", h: " << greyImage.height() << std::endl;

  return 0;
}

