#include <bits/stdc++.h>
#include <cmath>
#include <fstream>
using namespace std;

/* double x; */

int main() {
    system("clear");


    /* cin >> x; */

    ofstream myfile;
    myfile.open("wyniki.dat");
    double dx = 0.0001 * M_PI;
    double pi2 = 20 * M_PI;
    for(double x = 0; x <= pi2; x += dx) {
        /* myfile << x << " " << pow(cos(x), 2) << " " << cos(-0.2*x) << endl; */
        myfile << x << " " << pow(cos(x), 2) << " " << cos(x) << endl;
    }
    myfile.close();
    
    /* cout << M_PI; */

    return 0;
}
