#include <iostream>
#include <cstdlib>
#include <ctime>
#include <complex>

using namespace std;

// Funkcja porównująca dwa liczby zespolone
int cmp(const void* a, const void* b) {
    const complex<double>* c1 = static_cast<const complex<double>*>(a);
    const complex<double>* c2 = static_cast<const complex<double>*>(b);
    if (abs(*c1) < abs(*c2)) {
        return -1;
    } else if (abs(*c1) > abs(*c2)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Inicjalizacja generatora liczb pseudolosowych
    srand(time(NULL));

    // Tworzenie tablicy liczb zespolonych
    const int N = 10;
    complex<double> tab[N];
    for (int i = 0; i < N; ++i) {
        double re = rand() % 10 - 5;
        double im = rand() % 10 - 5;
        tab[i] = complex<double>(re, im);
    }

    // Wypisanie tablicy przed sortowaniem
    cout << "Przed sortowaniem:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << tab[i] << " ";
    }
    cout << endl;

    // Sortowanie tablicy
    qsort(tab, N, sizeof(complex<double>), cmp);

    // Wypisanie tablicy po sortowaniu
    cout << "Po sortowaniu:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << tab[i] << " ";
    }
    cout << endl;

    return 0;
}
