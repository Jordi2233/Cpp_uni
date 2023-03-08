#include <iostream>
using namespace std;
int l;
int tab[50];

void change(int *adres)
{
  for (l;l>=0;l--)
  {
      (*adres);
  }
//(*adres)=0;
}

int main()
{
    tab[5]=6;
    int a[l]={};
    change(&tab[5]);
    cout<<tab[5];
    return 0;
}
