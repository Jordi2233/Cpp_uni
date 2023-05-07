#include <iostream>
#include <vector>
#include <algorithm>

struct Sortuj {
    bool operator()(int a, int b) const {
        return a % 10 < b % 10;
    }
};

int main() {
    std::vector<int> v = {1, 5, 16, 12, 35, 6, 13, 45, 6, 8};
    std::sort(begin(v), end(v), Sortuj());

    for (int x : v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;
}
