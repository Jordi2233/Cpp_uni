#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void saveppm(string filename, int width, int height)
{
    ofstream file;
    file.open(filename);
    file << "P3" << endl;
    file << width << " " << height << endl;
    file << "255" << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            file << r << " " << g << " " << b << " ";
        }
        file << endl;
    }
    file.close();
    cout << "File saved as " << filename << endl;
}

int main()
{
    int width, height;
    string filename;
    cout << "Enter width of the image: ";
    cin >> width;
    cout << "Enter height of the image: ";
    cin >> height;
    cout << "Enter filename (with .ppm extension): ";
    cin >> filename;
    saveppm(filename, width, height);
    return 0;
}