#include <iostream>
using namespace std;

string color_s = "\x1b[";
string color_e = "\x1b[0m";
string test = "Test Cout";


int main() {
    system("clear");

    for (int i = 0; i < 36; i++) {
        cout << i << " " << color_s + to_string(i) + "m"+ test + color_e << "\n";
    }
    for (int i = 41; i < 46; i++) {
        cout << color_s + to_string(i) + "m"+ test + color_e << "\n";
    }

    return 0;
}
