#include <iostream>
#include <vector>

// template of std::ostream overloaded operator<< for vectors any type 
template <typename T> std::ostream& operator<<(std::ostream& os, std::vector<T> v)
{
    // print on screen all elements of vector
    for (auto& i: v)
    {
        os << i << " ";
    }
    return os;
}

int main()
{
    //testing using vector of integers
    std::vector<int> w = {2,3,4,5,5,67,7};
    std::cout << w << std::endl;
    //testing using vector of characters
    std::vector<char> c = {'a','b','v'};
    std::cout << c << std::endl;
    return 0;
}