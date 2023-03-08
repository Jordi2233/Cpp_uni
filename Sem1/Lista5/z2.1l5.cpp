#include <iostream>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void reverse(int array[], int array_size)
{

	int *pointer1 = array,

		*pointer2 = array + array_size - 1;
	while (pointer1 < pointer2) {
		swap(pointer1, pointer2);
		pointer1++;
		pointer2--;
	}
}

void print(int* array, int array_size)
{

	int *length = array + array_size,

		*position = array;
	std::cout << "Tablica = ";
	for (position = array; position < length; position++)
		std::cout << *position << " ";
}

int main()
{

	int array[] = { 1,2,3,4,5,6,7,8,9 };
	int arr2[] = { 1,2,3,4,5,6,7,8, 9 };

	std::cout << "Pierwotna tablica: ";
	print(arr2, 9);

	std::cout << "Odwrócona tablica: ";
	reverse(arr2, 9);
	print(arr2, 9);
	return 9;
}
