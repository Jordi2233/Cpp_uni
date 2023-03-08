#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int i, mode;
string q;
double res, first_num, second_num;


int main() {
    system("clear");
    while(i == 0) {
        cout << "----------------" << endl;
        cout << "Enter first number: ";
        cin >> first_num;
        cout << "Enter second number: ";
        cin >> second_num;
        cout << "1) Addition" << endl;
        cout << "2) Subtraction" << endl;
        cout << "3) Multiplication" << endl;
        cout << "4) Division" << endl;
        cout << "What you want to do: " << endl;
        cin >> mode;
        switch(mode) {
            case 1:
                res = first_num + second_num;
            break;
            case 2:
                res = first_num - second_num;
            break;
            case 3:
                res = first_num * second_num;
            break;
            case 4:
                res = first_num / second_num;
            break;

        }
        cout << "Result: " << res << endl;
        cout << "----------------" << endl;
        cout << "Do you want to do something more (Yes or No): ";
        cin >> q;
        transform(q.begin(), q.end(), q.begin(), ::tolower);
        if (q == "yes") {
            i = 0;   
        } else {
            i = 1;
        }
        system("clear");
}

    return 0;
}
