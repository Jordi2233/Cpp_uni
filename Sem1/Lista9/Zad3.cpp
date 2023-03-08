#include <fstream>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int width = 500;
    int height = 500;
    int frames = 600;
    double time_scale = 0.02;
    string file_name;
    string command;
    for (int i = 0; i < frames; i++)
    {
        file_name = "anim/sin_plot_" + to_string(i) + ".ppm";
        std::ofstream out(file_name);
        out << "P3" << std::endl;
        out << width << " " << height << std::endl;
        out << "255" << std::endl;
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                double x_scaled = (4.0 * (x - width / 2) / width);
                double y_scaled = (2.0 * y / height) - 1.0;
                int r, g, b;
                double y_sin = (sin(x_scaled * M_PI + time_scale * i)) / 2.0;
                if (y_scaled > y_sin - 0.01 && y_scaled < y_sin + 0.01)
                {
                    r = 255;
                    g = 153;
                    b = 51;
                }
                else
                {
                    r = 0;
                    g = 0;
                    b = 0;
                }
                out << r << " " << g << " " << b << " ";
            }
            out << std::endl;
        }

        out.close();
    }
    command = "ffmpeg -framerate 30 -i anim/sin_plot_%d.ppm -c:v libx264 -r 30 -pix_fmt yuv420p sin_animation.mp4 && mplayer `find . -name sin_animation.mp4`";
    system(command.c_str());
    return 0;
}
