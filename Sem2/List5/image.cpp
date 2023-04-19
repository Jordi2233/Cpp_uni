#include "image.h"

#include <fstream>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <cmath>

void Image::load(const std::string &filename)
{
    constexpr auto MAGIC = "P6";

    this->filename = filename;

    std::ifstream in(filename, std::ios::binary);
    if (!in)
        throw std::invalid_argument("failed to open \"" + filename + "\"");

    in >> magic;
    if (magic != MAGIC)
        throw std::logic_error("unknown magic naumber " + magic);

    in >> my_width >> my_height >> color_depth;

    if (!in || my_width < 0 || my_width > 10000 || my_height < 0 || my_height > 10000 || color_depth <= 0 ||
        color_depth > 255)
        throw std::logic_error("invalid image parameter(s): " + std::to_string(my_width) + " " +
                               std::to_string(my_height) + " " + std::to_string(color_depth));
    in.ignore(1);
    pixels.resize(my_height);
    for (auto &line : pixels)
    {
        line.resize(my_width);
        in.read(reinterpret_cast<char *>(&line[0]), my_width * sizeof(RGB));
        if (!in)
            throw std::logic_error("failed to read binary pixel data from file " + filename);
    }
}

void Image::save_as(const std::string &filename)
{
    std::ofstream out(filename, std::ios::binary);
    out << magic << "\n";
    out << my_width << " " << my_height;
    out << "\n"
        << color_depth << "\n";
    pixels.resize(my_height);
    for (auto &line : pixels)
    {
        line.resize(my_width);
        out.write(reinterpret_cast<char *>(&line[0]), my_width * sizeof(RGB));
    }
}

void Image::add_watermark()
{
    for (int row(my_height / 2); row < my_height; row++)
    {
        for (int column(my_width / 2); column < my_width; column++)
        {
            int r = (50 + pixels[row][column].red);
            pixels[row][column].red = std::min(r, 255);

            int g = (50 + pixels[row][column].green);
            pixels[row][column].green = std::min(g, 255);

            int b = (50 + pixels[row][column].blue);
            pixels[row][column].blue = std::min(b, 255);
        }
    }
}

void Image::blurr()
{
    std::vector<std::vector<RGB>> npx;
    npx.resize(my_height);
    for (auto &line : npx)
    {
        line.resize(my_width);
    }
    for (int row(0); row < my_height; row++)
    {
        npx[row] = pixels[row];
        for (int column(0); column < my_width; column++)
        {
            int r(0), g(0), b(0), count(0);
            for (int i(-1); i < 2; i++)
            {

                for (int j(-1); j < 2; j++)
                {
                    if (row + i >= 0 && row + i < my_height)
                    {
                        if (column + i >= 0 && column + i < my_width)
                        {
                            count++;
                            r += pixels[row + i][column + j].red;
                            g += pixels[row + i][column + j].green;
                            b += pixels[row + i][column + j].blue;
                        }
                    }
                }
            }
            npx[row][column].red = int(r / count);
            npx[row][column].green = int(g / count);
            npx[row][column].blue = int(b / count);
        }
        pixels[row] = npx[row];
    }
}

void Image::extract_layer(ColorLayer color_layer)
{
    for (auto &line : pixels)
    {
        for (auto &px : line)
        {
            switch (color_layer)
            {
            case ColorLayer::Red:
            {
                px.blue = px.green = 0;
            }
            case ColorLayer::Green:
            {
                px.blue = px.red = 0;
            }
            case ColorLayer::Blue:
            {
                px.red = px.green = 0;
            }
            default:
                break;
            }
        }
    }
}

void Image::filter()
{
    std::vector<std::vector<RGB>> npx;
    npx.resize(my_height - 1);
    for (auto &line : npx)
    {
        line.resize(my_width - 1);
    }
    for (int row(0); row < my_height - 1; row++)
    {
        for (int column(0); column < my_width - 1; column++)
        {
            npx[row][column].red = abs(pixels[row][column].red - pixels[row + 1][column + 1].red);
            npx[row][column].green = abs(pixels[row][column].green - pixels[row + 1][column + 1].green);
            npx[row][column].blue = abs(pixels[row][column].blue - pixels[row + 1][column + 1].blue);
        }
    }
    my_height--;
    my_width--;
    pixels.resize(my_height);
    for (auto &line : pixels)
    {
        line.resize(my_width);
    }
    for (int row(0); row < my_height; row++)
    {
        pixels[row] = npx[row];
    }
}

void Image::flip_horizontally()
{
    for (int row(0); row < int(my_height); row++)
    {
        for (int column(0); column < int(my_width / 2); column++)
        {
            pixels[row][column].red = pixels[row][column].red ^ pixels[row][my_width - column - 1].red;
            pixels[row][my_width - column - 1].red = pixels[row][column].red ^ pixels[row][my_width - column - 1].red;
            pixels[row][column].red = pixels[row][column].red ^ pixels[row][my_width - column - 1].red;

            pixels[row][column].green = pixels[row][column].green ^ pixels[row][my_width - column - 1].green;
            pixels[row][my_width - column - 1].green = pixels[row][column].green ^ pixels[row][my_width - column - 1].green;
            pixels[row][column].green = pixels[row][column].green ^ pixels[row][my_width - column - 1].green;

            pixels[row][column].blue = pixels[row][column].blue ^ pixels[row][my_width - column - 1].blue;
            pixels[row][my_width - column - 1].blue = pixels[row][column].blue ^ pixels[row][my_width - column - 1].blue;
            pixels[row][column].blue = pixels[row][column].blue ^ pixels[row][my_width - column - 1].blue;
        }
    }
}

void Image::flip_vertically()
{
    for (int row(0); row < int(my_height / 2); row++)
    {
        for (int column(0); column < int(my_width); column++)
        {
            pixels[row][column].red = pixels[row][column].red ^ pixels[my_height - row - 1][column].red;
            pixels[my_height - row - 1][column].red = pixels[row][column].red ^ pixels[my_height - row - 1][column].red;
            pixels[row][column].red = pixels[row][column].red ^ pixels[my_height - row - 1][column].red;

            pixels[row][column].green = pixels[row][column].green ^ pixels[my_height - row - 1][column].green;
            pixels[my_height - row - 1][column].green = pixels[row][column].green ^ pixels[my_height - row - 1][column].green;
            pixels[row][column].green = pixels[row][column].green ^ pixels[my_height - row - 1][column].green;

            pixels[row][column].blue = pixels[row][column].blue ^ pixels[my_height - row - 1][column].blue;
            pixels[my_height - row - 1][column].blue = pixels[row][column].blue ^ pixels[my_height - row - 1][column].blue;
            pixels[row][column].blue = pixels[row][column].blue ^ pixels[my_height - row - 1][column].blue;
        }
    }
}
void Image::inflate()
{
    my_height *= 2;
    my_width *= 2;
    pixels.resize(my_height);
    for (auto &line : pixels)
    {
        line.resize(my_width);
    }
    std::vector<std::vector<RGB>> npx;
    npx.resize(my_height);
    for (auto &line : npx)
    {
        line.resize(my_width);
    }
    for (int row(0); row < my_height / 2; row++)
    {
        for (int column(0); column < my_width / 2; column++)
        {
            npx[row * 2][column * 2] = pixels[row][column];
            npx[row * 2][column * 2 + 1] = pixels[row][column];
            npx[row * 2 + 1][column * 2] = pixels[row][column];
            npx[row * 2 + 1][column * 2 + 1] = pixels[row][column];
        }
    }
    for (int row(0); row < my_height; row++)
    {
        pixels[row] = npx[row];
    }
}

void Image::negative()
{
    for (int row(0); row < my_height; row++)
    {
        for (int column(0); column < my_width; column++)
        {
            pixels[row][column].red = 255 - pixels[row][column].red;
            pixels[row][column].green = 255 - pixels[row][column].green;
            pixels[row][column].blue = 255 - pixels[row][column].blue;
        }
    }
}

void Image::rotate_clockwise_90()
{
    std::vector<std::vector<RGB>> npx;
    npx.resize(my_width);
    for (auto &line : npx)
    {
        line.resize(my_height);
    }
    for (int row(0); row < my_height; row++)
    {
        for (int column(0); column < my_width; column++)
        {
            npx[column][row] = pixels[row][column];
        }
    }
    auto tmp = my_height;
    my_height = my_width;
    my_width = tmp;
    pixels.resize(my_height);
    for (auto &line : pixels)
    {
        line.resize(my_width);
    }
    for (int row(0); row < my_height; row++)
    {
        for (int column(0); column < my_width; column++)
        {
            pixels[row][column] = npx[row][column];
        }
    }
    flip_horizontally();
}

void Image::sepia()
{
    for (int row(0); row < my_height; row++)
    {
        for (int column(0); column < my_width; column++)
        {
            auto gray = (pixels[row][column].red * 0.3 + pixels[row][column].red * 0.59 + pixels[row][column].red * 0.11);
            pixels[row][column].red = std::min(int(gray) + 61, 255);
            pixels[row][column].green = std::min(int(gray) + 27, 255);
            pixels[row][column].blue = std::min(int(gray), 255);
        }
    }
}

void Image::shrink()
{
    std::vector<std::vector<RGB>> npx;
    npx.resize(int(my_height / 2));
    for (auto &line : npx)
    {
        line.resize(int(my_width / 2));
    }

    for (int row(0); row < my_height - 1; row = row + 2)
    {
        for (int column(0); column < my_width - 1; column = column + 2)
        {
            npx[int(row / 2)][int(column / 2)].red = (pixels[row][column].red + pixels[row][column + 1].red + pixels[row + 1][column].red + pixels[row + 1][column + 1].red) / 4;
            npx[int(row / 2)][int(column / 2)].green = (pixels[row][column].green + pixels[row][column + 1].green + pixels[row + 1][column].green + pixels[row + 1][column + 1].green) / 4;
            npx[int(row / 2)][int(column / 2)].blue = (pixels[row][column].blue + pixels[row][column + 1].blue + pixels[row + 1][column].blue + pixels[row + 1][column + 1].blue) / 4;
        }
    }

    my_height /= 2;
    my_width /= 2;
    pixels.resize(my_height);
    for (auto &line : pixels)
    {
        line.resize(my_width);
    }
    for (int row(0); row < my_height; row++)
    {
        pixels[row] = npx[row];
    }
}

void Image::to_grayscale()
{
    for (int row(0); row < my_height; row++)
    {
        for (int column(0); column < my_width; column++)
        {
            auto gray = (pixels[row][column].red * 0.3 + pixels[row][column].red * 0.59 + pixels[row][column].red * 0.11);
            pixels[row][column].red = std::min(int(gray), 255);
            pixels[row][column].green = std::min(int(gray), 255);
            pixels[row][column].blue = std::min(int(gray), 255);
        }
    }
}