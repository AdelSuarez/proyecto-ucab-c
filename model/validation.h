#include<iostream>
#include"../settings/style.h"
#include<conio.h>

using namespace std;

string isVoid(string text){

    string input;
    while(true){
        cout << text;
        getline(cin, input);
        if (input.empty()){
            cout << REDB "No se acepta una entrada vacia, vuelve a intentar.\n" NC;
        } else {\
            break;
        }

    }
    return input;

}

float validateNumber(string text) {
    float number;
    string input;

    while (true) {
        cout << text;
        getline(cin, input);

        // Verifica si la entrada está vacía
        if (input.empty()) {
            cout << REDB "No se acepta una entrada vacia, vuelve a intentar.\n" NC;
            continue;
        }

        // Convierte la entrada a float
        stringstream ss(input);
        ss >> number;

        if (ss.fail() || !ss.eof()) {
            cout << REDB "No se aceptan letras, vuelve a intentar.\n" NC;
        } else if (number < 0) {
            cout << REDB "Cantidad incorrecta, vuelve a intentarlo\n" NC;
        } else {
            break; // Sal del bucle, la entrada es válida
        }
    }
    return number;
}