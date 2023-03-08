#include <bits/stdc++.h>
#include <locale.h>
using namespace std;

string name = "Blazej Strzelecki";
string color_s = "\x1b[";
string color_e = "\x1b[0m";

int main() {
    setlocale(LC_CTYPE, "Polish");
    system("clear");
    srand(time(NULL));
    
/* for (int i = 0; i <= 10; i++) { */
    for(int i = 0; i < name.length(); i++) {
    
        string color_number = to_string( 31 + ( rand() % ( 36 - 31 + 1 ) ) ); 
        string letter = color_s + color_number + "m" + name[i] + color_e;
        cout << letter;
    }
    cout << endl;
/* } */
return 0;
}
