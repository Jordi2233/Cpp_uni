#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 5, 16, 12, 35, 6, 13, 45, 6, 8};
    std::sort(begin(v), end(v), [](int a, int b) { return a % 10 < b % 10; });

    for (int x : v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;
}
