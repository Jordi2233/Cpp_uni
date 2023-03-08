#include <iostream>
#include <cmath>

const int n = 1000000;

double computeSumA()
{
    double sum = 0.0;
    for (int j = 1; j <= n; j++)
    {
        double term = pow(-1, j + 1) / ((2 * j - 1) * 1.0);
        sum += term;
    }
    return 4 * sum;
}

double computeProduct()
{
    double product = 1.0;
    for (int j = 1; j <= n; j++)
    {
        double term = 4.0 * pow(j, 2) / (4.0 * pow(j, 2) - 1.0);
        product *= term;
    }
    return 2.0 * product;
}

double computeSumC()
{
    double sum = 0.0;
    for (int j = 1; j <= n; j++)
    {
        double term = 1.0 / pow(2 * j - 1, 2);
        sum += term;
    }
    return sqrt(8 * sum);
}

int main()
{
    double resultA = computeSumA();
    std::cout << "a) " << resultA << "; Pi: " << M_PI << std::endl;

    double resultB = computeProduct();
    std::cout << "b) " << resultB << "; Pi: " << M_PI << std::endl;

    double resultC = computeSumC();
    std::cout << "c) " << resultC << "; Pi: " << M_PI << std::endl;

    return 0;
}
