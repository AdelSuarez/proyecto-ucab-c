// #include<iostream>
// #include "struct.h"
using namespace std;


Seller* createSeller(long long int dni, string name, int day, int month, int year, int comission){
    Seller *seller = new Seller();
    seller->seller.dni = dni;
    seller->seller.name = name;
    seller->admissionDay.day = day;
    seller->admissionDay.month = month;
    seller->admissionDay.year = year;
    seller->commission = comission;

    seller->next = NULL;
    return seller;
}

void showSellers(Seller *list) {
    system("cls");

    Seller *current = new Seller();
    current = list;

    cout <<BLUE "\t\t\t\t-LISTA VENDEDORES-" NC<< endl;
    cout << BLACK BLUEB ;
    cout << left << setw(15) << "DNI" << setw(30) << "NOMBRE" << setw(30) << "ADMISION" << setw(12) << "COMISION" << endl;
    cout << NC;
    while(current != NULL){
        cout << left << setw(15) << current->seller.dni << setw(30) << current->seller.name  << current->admissionDay.day<<"/" << current->admissionDay.month<<"/"<< setw(28) << current->admissionDay.year << setw(12) << current->commission << endl;
        current = current->next;
    }
    cout << endl;
    cout << "Presione cualquier tecla para continuar";
    _getch();
}