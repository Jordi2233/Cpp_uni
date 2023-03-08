#include <bits/stdc++.h>
using namespace std;

int x;

int main() {
    system("clear");

    for (int i = -5; i <= 5; i++) {
    
        for (int j = -5; j <= 5; j++) {

            x = j * i;

            if (j != 10) {
                if ((x >= 10) | ((x < 0) & (x > -10)) ) {
                    cout << " " << x << "\t";
                }
                else if ((x >= 0) & (x < 10)) {
                    cout << "  " <<  x << "\t";
                }
                else {
                    cout << x << "\t";
                }
            } else {
                cout << "\t" << x << "\n";
            }
        }

        cout << "\n";

    }

    cout << "\n";

    return 0;
}
