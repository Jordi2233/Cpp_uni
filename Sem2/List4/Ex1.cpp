#include <iostream>
#include <vector>

int operator*(const std::vector<double> &v1, const std::vector<double> &v2)
{
    int sum = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        sum += v1[i] * v2[i];
    }
    return sum;
}

int main()
{
    system("clear");

    std::vector<double> v1 = {1, 2, 3, 4, 5};
    std::vector<double> v2 = {1, 2, 3, 4, 5};

    std::cout << v1 * v2 << std::endl;

    return 0;
}