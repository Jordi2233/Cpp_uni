#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>

double down_sum_double(int N)
{
	double sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += 1.0 / i;
	}
	return sum;
}

double up_sum_double(int N)
{
	double sum = 0;
	for (int i = N; i >= 1; i--)
	{
		sum += 1.0 / i;
	}
	return sum;
}

float down_sum_float(int N)
{
	float sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += 1.0f / i;
	}
	return sum;
}

float up_sum_float(int N)
{
	float sum = 0;
	for (int i = N; i >= 1; i--)
	{
		sum += 1.0f / i;
	}
	return sum;
}

int main()
{

	double N = 100000000;

	// Counting for 100 and 10000 with double
	for (int n = 100; n <= 10000; n *= 100)
	{
		std::cout << "Calculating sums using double type:" << std::endl;
		std::cout << "N = " << n << ": down_sum = " << std::setprecision(15) << down_sum_double(n)
				  << ", up_sum = " << std::setprecision(15) << up_sum_double(n)
				  << ", diff = " << std::setprecision(15) << up_sum_double(n) - down_sum_double(n) << std::endl;
	}

	// Counting for 100000000 with double
	std::cout << "Calculating sums using double type:" << std::endl;
	std::cout << "N = " << N << ": down_sum = " << std::setprecision(15) << down_sum_double(N)
			  << ", up_sum = " << std::setprecision(15) << up_sum_double(N)
			  << ", diff = " << std::setprecision(15) << up_sum_double(N) - down_sum_double(N) << std::endl;

	std::cout << std::endl;

	// Counting for 100 and 10000 with float
	for (int n = 100; n <= 10000; n *= 100)
	{
		std::cout << "Calculating sums using float type:" << std::endl;
		std::cout << "N = " << n << ": down_sum = " << std::setprecision(15) << down_sum_float(n)
				  << ", up_sum = " << std::setprecision(15) << up_sum_float(n)
				  << ", diff = " << std::setprecision(15) << up_sum_float(n) - down_sum_float(n) << std::endl;
	}

	// Counting for 100000000 with float
	std::cout << "N = " << N << ": down_sum = " << std::setprecision(15) << down_sum_float(N)
			  << ", up_sum = " << std::setprecision(15) << up_sum_float(N)
			  << ", diff = " << std::setprecision(15) << up_sum_float(N) - down_sum_float(N) << std::endl;

	return 0;
}
