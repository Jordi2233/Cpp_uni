#include <bits/stdc++.h>
#include <vector>

std::vector <long double> seq;
int n;
long double x;

int main() {
	std::cout << "Enter number of harmonic sequence: ";
	std::cin >> n;

    for (int i = 0; i <= n; i++){

       x = (long double)1/i;

       seq.push_back(x);
    }

    std::ofstream plot_file;

	plot_file.open("plot_file_2.dat");

	for (int i = 0; i <= n; i++)
	{
		plot_file << std::setprecision(1000);
		plot_file << i  << " " << seq[i] << std::endl;
	}

	plot_file.close();



    return 0;
}