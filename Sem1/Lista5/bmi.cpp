#include <iostream>

float BMI(float a, float b)
{
    float bmi;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    bmi = b / (a * a);
    return bmi;
}
void BMIprint(float BMI)
{
    float bmi;
    std::cout << "twoje bmi to " << bmi << std::endl;
}
float readHeight()
{
    float abc;
    std::cout << "podaj swój wzrost w metrach " << std::endl;
    std::cin >> abc;
    return abc;
}
float readMass()
{
    float wg;
    std::cout << "podaj swoją wage w kg " << std::endl;
    std::cin >> wg;
    return wg;
}
int main()
{

    BMIprint(BMI(readHeight(), readMass()));
    return 0;
}
