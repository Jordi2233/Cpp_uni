#include <iostream>
#include <cmath>
class Fraction
{
    constexpr int64_t gcd(int64_t a, int64_t b) { return b == 0 ? a : gcd(b, a % b); }

    int64_t n, d;

public:
    constexpr Fraction(int64_t n, int64_t d = 1) : n(n / gcd(n, d)), d(d / gcd(n, d)) {}

    constexpr int64_t num() const { return n; }
    constexpr int64_t den() const { return d; }

    constexpr Fraction &operator*=(const Fraction &rhs)
    {
        int64_t new_n = n * rhs.n / gcd(n * rhs.n, d * rhs.d);
        d = d * rhs.d / gcd(n * rhs.n, d * rhs.d);
        n = new_n;
        return *this;
    }

    constexpr Fraction &operator+=(const Fraction &rhs)
    {
        int64_t lcm = d * rhs.d / gcd(d, rhs.d);
        n = n * (lcm / d) + rhs.n * (lcm / rhs.d);
        d = lcm;
        int64_t g = gcd(n, d);
        n /= g;
        d /= g;
        return *this;
    }

    constexpr Fraction &operator-=(const Fraction &rhs)
    {
        int64_t lcm = d * rhs.d / gcd(d, rhs.d);
        n = n * (lcm / d) - rhs.n * (lcm / rhs.d);
        d = lcm;
        int64_t g = gcd(n, d);
        n /= g;
        d /= g;
        return *this;
    }

    constexpr Fraction &operator/=(const Fraction &rhs)
    {
        n = n * rhs.d;
        d = d * rhs.n;
        int64_t g = gcd(n, d);
        n /= g;
        d /= g;
        return *this;
    }

    constexpr double to_double() const
    {
        return static_cast<double>(n) / static_cast<double>(d);
    }
};

std::ostream &operator<<(std::ostream &out, const Fraction &f)
{
    return out << f.num() << '/' << f.den();
}

constexpr bool operator==(const Fraction &lhs, const Fraction &rhs)
{
    return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}

constexpr bool operator!=(const Fraction &lhs, const Fraction &rhs)
{
    return !(lhs == rhs);
}

constexpr Fraction operator*(Fraction lhs, const Fraction &rhs)
{
    return lhs *= rhs;
}

constexpr Fraction operator+(Fraction lhs, const Fraction &rhs)
{
    return lhs += rhs;
}

constexpr Fraction operator-(Fraction lhs, const Fraction &rhs)
{
    return lhs -= rhs;
}

constexpr Fraction operator/(Fraction lhs, const Fraction &rhs)
{
    return lhs /= rhs;
}
constexpr int MAX_N_A = 100;
constexpr int MAX_N_B = 20;
constexpr int MAX_N_C = 15;

void calculate_sum_a() {
    std::cout << "Sum A:\n";
    Fraction sum{0, 1};
    for (int N = 1; N <= MAX_N_A; ++N) {
        Fraction term{1, N * (N + 1)};
        sum += term;
        std::cout << "N = " << N << ", " << sum << " " << sum.to_double() << '\n';
    }
}

void calculate_sum_b() {
    std::cout << "\nSum B:\n";
    Fraction sum{0, 1};
    for (int N = 1; N <= MAX_N_B; ++N) {
        int sign = (N % 2 == 0) ? 1 : -1;
        Fraction term{sign, N};
        sum += term;
        std::cout << "N = " << N << ", " << sum << " " << sum.to_double() << '\n';
    }
}

void calculate_sum_c() {
    std::cout << "\nSum C:\n";
    Fraction sum{0, 1};
    for (int N = 1; N <= MAX_N_C; ++N) {
        int64_t denominator = static_cast<int64_t>(pow(2, N)) * N;
        Fraction term{1, denominator};
        sum += term;
        std::cout << "N = " << N << ", " << sum << " " << sum.to_double() << '\n';
    }
}

int main() {
    calculate_sum_a();
    calculate_sum_b();
    calculate_sum_c();
    return 0;
}
