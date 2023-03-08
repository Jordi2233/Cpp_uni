#include <fstream>
#include <cmath>

int main() {
    int width = 500;
    int height = 500;

    std::ofstream out("sin_plot.ppm");
    out << "P3" << std::endl;
    out << width << " " << height << std::endl;
    out << "255" << std::endl;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double x_scaled = (2.0 * x / width) - 1.0;
            double y_scaled = (2.0 * y / height ) - 1.0;
            int r,g,b;
            double y_sin = (sin(x_scaled*M_PI)) / 2.0;
            if(y_scaled > y_sin - 0.01 && y_scaled < y_sin + 0.01 ){
                r = 0;
                g = 0;
                b = 255;
            } else {
                r = 255;
                g = 255;
                b = 255;
            }
            out << r << " " << g << " " << b << " ";
        }
        out << std::endl;
    }

    out.close();
    return 0;
}
