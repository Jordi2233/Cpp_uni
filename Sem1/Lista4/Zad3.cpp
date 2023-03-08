#include <bits/stdc++.h>

int number_of_attempts;
int q, start, end, ans;

int random_number_generator(int start, int end)
{

	int random_number;
	int range = end - start + 1;

	random_number = std::rand() % range + start;

	return random_number;
}

int main()
{
	system("clear");
	srand(time(NULL));

	std::cout << "Enter start of range: ";
	std::cin >> start;
	std::cout << "Enter end of range: ";
	std::cin >> end;

	q = random_number_generator(start, end);

	while (ans != q)
	{
		system("clear");
		std::cout << "Enter your number: ";
		std::cin >> ans;
		if (ans > q)
		{
			system("clear");
			std::cout << "Wrong number! Too high! Try again: ";
		}
		else if (ans < q)
		{
			std::cout << "Wrong number! Too low! Try again: ";
		}
		number_of_attempts++;
	}
	system("clear");
	std::cout << "Good job! The number is: " << q << std::endl;
	std::cout << "You did it in " << number_of_attempts << " attempts" << std::endl;

	return 0;
}