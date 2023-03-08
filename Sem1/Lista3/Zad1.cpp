#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main(void) {

    system("clear");

    const int W = 20;
    const int H = 20;
    for (int j = 0; j < H; j++) {
        for (int i = 0; i < W; i++) {
            int r = (i/float(W)) * 255;
            int g = (i/float(H)) * 155;
            int b = (i/float(W)) * 55;
            cout<<"\x1b[48;2;" << r << ";" << g << ";" << b << "m \x1b[0m";
        }

        cout << endl;
    }

    return 0;
}
