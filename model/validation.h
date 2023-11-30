#include<iostream>
#include"../settings/style.h"
#include<conio.h>

using namespace std;

int validateNumber(string text) {
    int number;

    while (true) {
        cout << text;
        cin >> number;

        if (cin.fail()) {
            cin.clear(); // Restablece el estado de cin a 'bueno'
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada incorrecta
            cout << REDB "No se aceptan letras, vuelve a intentar." NC<< endl;
            getch();
        } else {
            break; // Sal del bucle, la entrada es válida
        }
    }
    return number;
}

