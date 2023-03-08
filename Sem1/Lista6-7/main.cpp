#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    int keyonoff = 1, wo = 600, ho = 600, zmienna = 0;
    const int N = 5;
    float x = wo / 2, y = ho / 2, g = 9.81, t = 0.01;
    sf::CircleShape obj[N];

    sf::RenderWindow window(sf::VideoMode(wo, ho), "Nasze okno");
    // tab r; tab x, tab y, tab v
    float pr[N] = { 12.0, 17.5, 5.0, 41.2, 30.0};
    float xx[N] = { x - pr[0], x - pr[1], x - pr[2], x - pr[3], x - pr[4] };
    float yy[N] = { y - pr[0], y - pr[1], y - pr[2], y - pr[3], y - pr[4] };
    float vx[N] = { 10, 51, 23, 12.3, 8.1 };
    float vy[N] = { 100, 51, 35, 67, 22 };
    int tab[3][N] = { {200, 150, 190, 130, 210}, { 0, 0, 0, 0, 0 }, {100, 80, 140, 150, 90} };
    // tablica obj
    for (int i = 0; i < N; i++) {
        obj[i] = sf::CircleShape(pr[i]);
        obj[i].setFillColor(sf::Color(tab[0][i], tab[1][i], tab[2][i], 255));
    }
    while (window.isOpen()) // dopoki okno jest otwarte...
    {
        // w tym obiekcie klasy sf::Event
        // bedziemy mieli informacje co zrobil uzytkownik
        sf::Event event;
        while (window.pollEvent(event)) {
            // uzytkownik kliknal zamkniecie okna
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                keyonoff = 1 - keyonoff;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }
        // aktu x/sprawdzenie

        for (int i = 0; i < N; i++) {
            if (xx[i] >= wo - 2 * pr[i]) { // prawo
                vx[i] *= -1;
            }
            else if (xx[i] <= 0) {   // lewo
                vx[i] *= -1;
            }

            if (yy[i] <= 0) {   // gora
                vy[i] *= -1;
            }
            else if (yy[i] >= ho - 2 * pr[i]) {  // dol
                vy[i] *= -1;
            }
            // zwalnianie + zmiana predk
            vx[i] *= 0.9999;
            vy[i] *= 0.9999;
            vy[i] += g * t;
            // zmiana polozen
            xx[i] += vx[i]*t;
            yy[i] += vy[i] * t;

            if (yy[i] >= ho - 2 * pr[i])
                yy[i] = ho - 2 * pr[i];
            
            tab[0][i] = yy[i] * 255 / ho;   // czerw w zalez od wysok
            tab[1][i] = xx[i] * 255 / wo;   // ziel w zalez od szer

            obj[i].setFillColor(sf::Color(tab[0][i], tab[1][i], tab[2][i], 255));
            obj[i].setPosition(xx[i], yy[i]);
        }
        // czyszczenie (na czarno)
        window.clear(sf::Color::Black);
        // rysuj kolo w zaleznosci od stanu zmiennej keyonoff
        if (keyonoff) {
            for (int i = 0; i < N; i++) {
                window.draw(obj[i]);
            }
        }
        window.display();
    }
    return 0;
}