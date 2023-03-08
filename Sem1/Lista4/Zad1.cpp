#include <iostream>
#include <vector>

std::vector<int> arr = {1, 2, 3, 4, 5};

int new_arr[5] = {1, 2, 3, 4, 5};

int new_len;

void hello()
{
    std::cout << "Hello World!" << std::endl;
}

float number(float num)
{
    // std::cout << num << std::endl;
    return num;
}

int sum(int x, int y)
{
    return x + y;
}

int multi(int x, float y, float z)
{
    int multiplication = x * y * z;
    // multiplication = (int)multiplication;
    std::cout << multiplication << std::endl;
    return multiplication;
}

int arr_il(std::vector<int> arr)
{

    int res = 1;

    int arr_len = arr.size();

    for (const auto &num : arr)
    {
        res *= num;
    }
    std::cout << res << std::endl;

    return res;
}

int arr_len(int* x)
{
    int x_len = 0;
    // x_len = sizeof(x) / sizeof(x[0]);
    x_len = sizeof(x) / sizeof(int);

    return x_len;
}

int main()
{
    system("clear");

    std::cout << "Arr len = " << arr_len(new_arr) << std::endl;

    new_len = sizeof(new_arr) / sizeof(new_arr[0]);
    std::cout << "Arr len = " << new_len << std::endl;

    hello();
    number(1.2);
    sum(1, 2);
    multi(3, 1.5, 1.3);
    arr_il(arr);
    return 0;
}