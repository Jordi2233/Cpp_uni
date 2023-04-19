#include "image.h"
#include <string>
#include <iostream>
int main(int argc, char **argv)
{
    Image image;
    image.load(argv[1]);
    image.blurr();
    image.extract_layer(ColorLayer::Blue);
    image.add_watermark();
    image.filter();
    image.flip_horizontally();
    image.flip_vertically();
    image.inflate();
    image.negative();
    image.rotate_clockwise_90();
    image.sepia();
    image.shrink();
    std::cout << image.height();
    std::cout << image.width();

    image.save_as("x.ppm");
    return 0;
}
