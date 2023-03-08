#include <bits/stdc++.h>
#include <vector>
// #include <fstream>
// #include <cstdlib>
int n;

std::vector<long double> fib = {0, 1};

// Najgorszy możliwy sposób
// int fib_seq(int n)
// {
// 	if (n <= 1)
// 		return n;
// 	return fib_seq(n - 1) + fib_seq(n - 2);
// }

int main()
{
	system("clear");

	std::cout << "Enter number of fibonacci sequence: ";
	std::cin >> n;

	// for (int i = 0; i <= n; i++)
	// {
	// 	fib.push_back(fib_seq(i));
	// }

	for (int i = 2; i <= n; i++)
	{
		fib.push_back(fib[i - 1] + fib[i - 2]);
	}

	std::ofstream plot_file;

	plot_file.open("plot_file.dat");

	for (int i = 1; i <= n; i++)
	{
		plot_file << std::setprecision(1000);
		plot_file << i - 1 << " " << fib[i] << std::endl;
	}

	plot_file.close();


	return 0;
}