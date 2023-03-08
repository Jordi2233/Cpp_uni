#include <bits/stdc++.h>
using namespace std;

int main()
{
    system("clear");

	int n; 
	unsigned int factorial = 1;

	cout<<"Enter n: ";
	cin>>n;

	for(int i = n ; i > 1; i--)
		factorial*=i; 
    /* cout << setprecision(10000); */
	cout<<n<<"! = "<<factorial<<endl;

	return 0;
}

/* Mój komputer potrafi wypisać tylko 1754! ponieważ potem stwierdza, że liczba jest zbyt duża i wypisuje inf - nieskończoność */
