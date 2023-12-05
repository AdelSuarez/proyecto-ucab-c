#include<iostream>
#include"../settings/style.h"
#include<conio.h>

using namespace std;

float validateNumber(string text) {
    float number;

    while (true) {
        cout << text;
        cin >> number;

        if (cin.fail()) {
            cin.clear(); // Restores the state of cin to 'good'
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards the incorrect input
            cout << REDB "No se aceptan letras, vuelve a intentar." NC<< endl;
        } else {
            break; // Exit the loop, the input is valid
        }
    }
    return number;
}
