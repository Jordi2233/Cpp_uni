#include <iostream>
#include <vector>

// Napisz program, który wypisze średnią N liczb losowych z zakresu od 0.0 do 1.0. Zadanie
// wykonaj dla różnych N (od 10 do 5000). Narysuj wykres s(N)

float rand_num()
{
	float res;

	res = (float)rand() / RAND_MAX;

	return res;
}

std::vector<float> arr_generator(int quantity)
{
	std::vector<float> res_arr;

	for (int i = 0; i < quantity; i++)
	{
		res_arr.push_back(rand_num());
	}

	return res_arr;
}

float arr_ave(std::vector<float> arr)
{

	float res, sum = 0;
	int arr_len = 0;

	for (const auto &value : arr)
	{
		sum += value;
	}

	arr_len = arr.size();

	res = sum / arr_len;

	return res;
}

int main()
{
	system("clear");
	srand(time(NULL));

	std::vector<float> arr = arr_generator(3);

	for (const auto &value : arr)
	{
		std::cout << value << std::endl;
	}

	std::cout << "AVG: " << arr_ave(arr) << std::endl;

	return 0;
}