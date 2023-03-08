#include <iostream>
using namespace std;

string r_s = "\x1b[41m";
string r_e = "\x1b[0m";

string y_s = "\x1b[43m";
string y_e = "\x1b[0m";

int main() {
      

    system("clear");
    cout << r_s + "* * *" + r_e + "\t" + y_s + " * * *" + y_e << endl;
    cout << r_s + "*     *" + r_e + "\t" + y_s + "*     *" + y_e << endl;
    cout << r_s + "*     *" + r_e + "\t" + y_s + "*" + y_e  << endl;
    cout << r_s + "* * *" + r_e + "\t" + y_s + "   *" + y_e << endl;
    cout << r_s + "*     *" + r_e + "\t" + y_s + "      *" + y_e << endl;
    cout << r_s + "*     *" + r_e + "\t" + y_s + "*     *" + y_e << endl;
    cout << r_s + "*  * *" + r_e + "\t" + y_s + " * * *" + y_e << endl;
    
    return 0;

}
