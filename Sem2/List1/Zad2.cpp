#include <iostream>
#include <cmath>

// method a)
double pi_approx_a(int i)
{
	auto t = 1 / sqrt(3.0);
	for (int j = 0; j < i; j++)
	{
		t = (sqrt((t * t) + 1) - 1) / t;
	}
	return 6 * pow(2, i) * t;
}

// method b)
double pi_approx_b(int i)
{
	auto t = 1 / sqrt(3.0);
	for (int j = 0; j < i; j++)
	{
		t = t / (sqrt((t * t) + 1) + 1);
	}
	return 6 * pow(2, i) * t;
}

int main()
{
	double pi_a, pi_b, pi_exact = M_PI;
	double error_a, error_b;

	for (int i = 0; i <= 30; i++)
	{
		pi_a = pi_approx_a(i);
		pi_b = pi_approx_b(i);
		error_a = abs(pi_exact - pi_a);
		error_b = abs(pi_exact - pi_b);

		std::cout << "i = " << i << std::endl;
		std::cout << "Method a): pi ~= " << pi_a << ", error = " << error_a << std::endl;
		std::cout << "Method b): pi ~= " << pi_b << ", error = " << error_b << std::endl;
		if (error_a < error_b)
		{
			std::cout << "Method a) has a smaller error" << std::endl;
		}
		else if (error_b < error_a)
		{
			std::cout << "Method b) has a smaller error" << std::endl;
		}
		else
		{
			std::cout << "Both methods have the same error" << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}
