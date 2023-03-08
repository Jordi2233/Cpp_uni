#include <bits/stdc++.h>
#include <conio.h>

int number_of_attempts = 1;
int q, start, ans, u;

int random_number_generator(int start, int end)
{

	int random_number;
	int range = end - start + 1;

	random_number = std::rand() % range + start;

	return random_number;
}

void justify_start(int just)
{
	for (int i = 0; i < just; i++)

	{
		std::cout << std::endl;
	}
}

void justify_end()
{
	for (int i = 0; i < 15; i++)
	{
		std::cout << std::endl;
	}
}
void game(int range, int lvl)
{
	int number_of_attempt = 1;
	ans = 0;

	srand(time(NULL));
	q = random_number_generator(start = 0, range);

	ans = 0;
	justify_start(15);
	std::cout.width(54);
	std::cout << "Lvl " << lvl << ". Enter your number from 0 to " << range << ": ";
	std::cin >> ans;
	justify_end();
	while (ans != q)
	{
		system("clear");
		if (ans > q)
		{
			justify_start(15);
			std::cout.width(84);
			std::cout << "Wrong number! To high! Try again: ";
			std::cin >> ans;
			justify_end();
		}
		else if (ans < q)
		{
			justify_start(15);
			std::cout.width(84);
			std::cout << "Wrong number! To low! Try again: ";
			std::cin >> ans;
			justify_end();
		}
		number_of_attempt++;
	}
	system("clear");
	u = 0;
	while (u != 32)
	{
		_kbhit();

		justify_start(12);
		std::cout.width(86);
		std::cout << "\x1b[32mGood job!\x1b[0m The number is " << ans << std::endl;
		std::cout.width(68);
		std::cout << "You did it in " << number_of_attempt << " attempts" << std::endl;
		justify_start(3);
		std::cout.width(79);
		std::cout << "Press {space} to go next!";
		justify_end();
		u = _getche();
	}
}