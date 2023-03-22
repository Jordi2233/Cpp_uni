#include <iostream>

struct Link
{
	int value;
	Link *next = nullptr;
};

int sum(Link *head)
{
	int res = 0;
	while (head != nullptr)
	{
		res += head->value;
		head = head->next;
	}
	return res;
}

int size(Link *head)
{
	int res = 0;
	while (head != nullptr)
	{
		res++;
		head = head->next;
	}
	return res;
}

void release(Link *head)
{
	while (head != nullptr)
	{
		Link *temp = head;
		head = head->next;
		delete temp;
	}
}

void print(Link *head)
{
	while (head != nullptr)
	{
		std::cout << head->value << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

void reverse(Link *&head)
{
	Link *prev = nullptr;
	Link *curr = head;
	Link *next = nullptr;

	while (curr != nullptr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

int main()
{
	system("clear");

	Link *head = new Link{1};
	head->next = new Link{2};
	head->next->next = new Link{3};
	head->next->next->next = new Link{4};
	std::cout << "Sum: " << sum(head) << std::endl;
	std::cout << "Size: " << size(head) << std::endl;
	print(head);
	reverse(head);
	print(head);
	release(head);

	return 0;
}