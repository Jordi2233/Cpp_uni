#include <iostream>
#include <numeric>

using namespace std;

// a. Zwraca sumę size pierwszych elementów tablicy tab
int suma(const int tab[], unsigned size) {
    return accumulate(tab, tab + size, 0);
}

// b. To samo co powyżej, ale wynik przekazywany jest poprzez result
void suma(const int tab[], unsigned size, int* result) {
    *result = accumulate(tab, tab + size, 0);
}

// c. Wypisuje size pierwszych elementów tablicy w strumieniu out, np. w std::cout
void pisz(const int* tab, size_t size, ostream * out) {
    for (size_t i = 0; i < size; ++i) {
        *out << tab[i] << " ";
    }
    *out << endl;
}

// d. Zapisuje w tablicy kolejne liczby całkowite, od 0 do size - 1
void iota(int tab[], unsigned size) {
    for (unsigned i = 0; i < size; ++i) {
        tab[i] = i;
    }
}

// e. Odwraca kolejność size pierwszych elementów w tablicy tab
void reverse(int* tab, size_t size) {
    for (size_t i = 0; i < size / 2; ++i) {
        swap(tab[i], tab[size - i - 1]);
    }
}

// f. Oblicza iloczyn skalarny elementów 2 tablic o rozmiarze size
int dot_product(const int* tab1, const int* tab2, size_t size) {
    return inner_product(tab1, tab1 + size, tab2, 0);
}

int main() {
    // Testy dla poszczególnych funkcji
    int tab[] = { 1, 2, 3, 4, 5 };
    int result;

    cout << "suma: " << suma(tab, 3) << endl;
    suma(tab, 3, &result);
    cout << "suma z wynikiem przekazywanym przez wskaźnik: " << result << endl;

    pisz(tab, 3, &cout);

    iota(tab, 5);
    pisz(tab, 5, &cout);

    reverse(tab, 5);
    pisz(tab, 5, &cout);

    int tab1[] = { 1, 2, 3 };
    int tab2[] = { 4, 5, 6 };

    cout << "iloczyn skalarny: " << dot_product(tab1, tab2, 3) << endl;

    return 0;
}
