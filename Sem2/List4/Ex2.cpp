#include <iostream>
#include <cmath>

double find_root(double (*f)(double), double a, double b, double tolerance = 1e-10)
{
    double fa = f(a);
    double fb = f(b);

    if (fa * fb > 0)
    {
        throw std::invalid_argument("f(a) and f(b) must have opposite signs");
    }

    while (std::abs(b - a) > tolerance)
    {
        double c = (a + b) / 2.0;
        double fc = f(c);

        if (fc == 0)
        {
            return c;
        }
        else if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }
    }

    return (a + b) / 2.0;
}

int main()
{

    double (*f)(double) = [](double x)
    { return cos(x); };
    std::cout << find_root(f, 0, 2, 0.0001) << std::endl;

    return 0;
}