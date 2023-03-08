#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 800;
const int MAX_ITER = 1000;
const double X_MIN = -2;
const double X_MAX = 1;
const double Y_MIN = -1.5;
const double Y_MAX = 1.5;

int main() {
    // Open a file for the output
    ofstream f("fractal.ppm");

    // Write the header for the PPM file
    f << "P3" << endl;
    f << WIDTH << " " << HEIGHT << endl;
    f << "255" << endl;

    // Iterate over each pixel
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Convert pixel coordinates to complex numbers
            double c_re = X_MIN + (x / (double)WIDTH) * (X_MAX - X_MIN);
            double c_im = Y_MAX - (y / (double)HEIGHT) * (Y_MAX - Y_MIN);
            complex<double> c(c_re, c_im);

            // Initialize the starting point
            complex<double> z(0, 0);

            // Iterate until the point escapes or we reach the maximum number of iterations
            int n;
            for (n = 0; n < MAX_ITER; n++) {
                z = z * z + c;
                if (abs(z) > 2) {
                    break;
                }
            }

            // Color the pixel based on how many iterations it took to escape
            if (n == MAX_ITER) {
                f << "255 255 255 "; // White color
            } else {
                int color = (int)((double)n / MAX_ITER * 255);
                f << color << " " << color << " " << color << " ";
            }
        }
        f << endl;
    }

    // Close the file
    f.close();
    return 0;
}
