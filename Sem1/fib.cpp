#include <bits/stdc++.h>
#include <vector>
#include <iostream>

std::vector<long double> fib = {0, 1};
int x;

int main()
{
    system("clear");

    std::cout << "Enter last element of Fibonacci sequence: ";
    std::cin >> x;

    for (int i = 2; i < x; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    std::cout << std::setprecision(10000);
    std::cout << fib[x - 1] << std::endl;

    return 0;
}
