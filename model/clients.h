#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include "struct.h"
#include "validation.h"
#include "../settings/style.h"

using namespace std;


// FIND ARTICLE (SEARCH) ---------------------------------------------------
Client* findCLient(Client *&list, long long int dni, Client *&previous) {
    Client *current = list;
    previous = NULL;

    while (current != NULL && current->client.dni != dni) {
        previous = current;
        current = current->next;
    }

    return current;
}


// CREATE CLIENT ---------------------------------------------------------------------
Client* createClient(long long int dni, string name, string address, long long int number){
    Client *client = new Client();
    client->client.dni = dni;
    client->client.name = name;
    client->address = address;
    client->number = number;

    client->next = NULL;
    return client;
}


// ADD CLIENT ---------------------------------------------------------------------
void addClient(Client *&list, Client *client, bool isFile, void (*fileUploadFunc)(Client *&) ) {
    Client *current = list;

    if (list == NULL || current->client.dni >= client->client.dni) {
        client->next = list;
        list = client;
    } else {
        while (current->next != NULL && current->next->client.dni < client->client.dni) {
            current = current->next;
        }
        client->next = current->next;
        current->next = client;
    }

    if (!isFile){
        cout << BLACK GREENB "Agregado con exito" NC;

    }
    fileUploadFunc(list);
}

void showClients(Client *list) {
    system("cls");

    Client *current = new Client();
    current = list;

    cout <<BLUE "\t\t\t\t-LISTA CLIENTES-" NC<< endl;
    cout << BLACK BLUEB ;
    cout << left << setw(15) << "DNI" << setw(30) << "NOMBRE" << setw(30) << "DIRECCION" << setw(12) << "NUMERO" << endl;
    cout << NC;
    while(current != NULL){
        cout << left << setw(15) << current->client.dni << setw(30) << current->client.name << setw(30) << current->address << setw(12) << current->number << endl;
        current = current->next;
    }
    cout << endl;
    cout << "Presione cualquier tecla para continuar";
    _getch();
}

void remove(Client *&, Client *, Client *, long long int ); 
void removeClient(Client *&list, long long int dni){
    string option;
    Client *previous = NULL;
    Client *current = findCLient(list, dni, previous);

    if (current != NULL){
        fflush(stdin);
        cout << "Cliente: " << current->client.name << endl;
        cout << "Desea eliminar el cliente (s/n) >> ";
        getline(cin, option);
        if ((option == "s") ||(option == "S")){
            remove(list,current, previous,  dni);
        } else {
            return;
        }

    }

}

void remove(Client *&list, Client *current, Client *previous, long long int dni) {

    if (current == NULL) {
        cout << BLACK REDB " Articulo no encontrado!" NC;
        _getch();
        return;
    }
    if (previous == NULL) { // El artículo a eliminar es el primer elemento
        list = current->next;
    } else { // El artículo a eliminar está en medio o al final de la lista
        previous->next = current->next;
    }
    delete current;
    cout << BLACK GREENB " Articulo borrado con exito!" NC;
    _getch();
}


void editClient(Client *&list, long long int dni, void (*fileUploadFunc)(Client *&)){
    bool isName = false, isDNI = false, isAddress = false, isNumber = false;
    string newName, newAddress;
    long long int newDNI, newNumber;
    int option;
    Client *previous = NULL;
    Client *current = findCLient(list, dni, previous);

    do {
        system("cls");
        fflush(stdin);
        cout << BLUE "\t-OPCIONES-" NC<< endl;
        cout << left << setw(1) << "1-" << setw(12) << "Nombre"<< "| " << setw(15) << current->client.name << (isName ? GREEN "*" NC: "") << endl;
        cout << left << setw(1) << "2-" << setw(12) << "DNI"<< "| " << setw(15) << current->client.dni << (isDNI ? GREEN "*" NC: "") << endl;
        cout << left << setw(1) << "3-" << setw(12) << "Direccion"<< "| " << setw(15) << current->address << (isAddress ? GREEN "*" NC: "") << endl;
        cout << left << setw(1) << "4-" << setw(12) << "Numero"<< "| " << setw(15) << current->number << (isNumber ? GREEN "*" NC: "") << endl;
        cout << "0- Salir" << endl;

        option = validateNumber("Introduce la opcion >> ");
        cin.ignore();

        switch (option)
        {
        case 1:
            cout << endl;
            cout << "+\tEditar nombre" << endl;
            cout << "| Nuevo nombre: ";
            getline(cin, newName);
            current->client.name = newName;
            cout << "|" <<endl;
            cout << "+ "<<GREEN "Nombre editado con exito!" NC;
            isName = true;
            fileUploadFunc(list);
            _getch();
            break;
            break;

        case 2:
            cout << endl;
            cout << "+\tEditar DNI" << endl;
            newDNI = validateNumber("| Nuevo DNI >> ");
            current->client.dni = newDNI;
            cout << "|" <<endl;
            cout << "+ "<<GREEN "DNI editado con exito!" NC;
            isDNI = true;
            fileUploadFunc(list);
            _getch();
            break;

        case 3:
            cout << endl;
            cout << "+\tEditar direccion" << endl;
            cout << "| Nueva direccion: ";
            getline(cin, newAddress);
            current->address = newAddress;
            cout << "|" <<endl;
            cout << "+ "<<GREEN "Direccion editada con exito!" NC;
            isAddress = true;
            fileUploadFunc(list);
            _getch();
            break;
        case 4:
            cout << endl;
            cout << "+\tEditar numero" << endl;
            newNumber = validateNumber("| Nuevo numero >> ");
            current->number = newNumber;
            cout << "|" <<endl;
            cout << "+ "<<GREEN "Stock editado con exito!" NC;
            isNumber = true;
            fileUploadFunc(list);
            _getch();
            break;

        case 0:
            break;
        
        default:
            cout << REDB "La opcion no existe" NC;
            _getch();
        }

    } while(option != 0);
}

void viewClient(Client *);
void searchClient(Client* list){
    Client* current = list;
    int option, count ;
    string name, address;
    long long int dni;
    do {
        system("cls");
        count = 0;
        cout << BLUE "\t-BUSCAR ARTICULO- " NC<< endl;
        cout << "1- Nombre" << endl;
        cout << "2- DNI" << endl;
        cout << "3- Direccion" << endl;
        cout << "0- salir" << endl;
        cout << "Introduce la opcion >> ";


        option = validateNumber("Introduce la opcion >> ");
        cin.ignore();

        switch (option)
        {
        case 1:
            system("cls");
            cout << BLUE "\t BUSQUEDA POR NOMBRE" NC<< endl;
            cout << "Introduce el nombre >> ";
            getline(cin, name);
            while(current != NULL) {
                if(current->client.name == name ) {
                    viewClient(current);
                    count++;
                }
                current = current->next;
            }
            cout << endl <<(count == 0? RED : GREEN) << "Busqueda terminada " << "[" << count <<"]" NC<< endl;
            _getch();
            break;

        case 2:
            system("cls");
            cout << BLUE "\t BUSQUEDA POR DNI" NC<< endl;
            dni = validateNumber("Introduce el DNI >> ");
            while(current != NULL) {
                if(current->client.dni == dni ) {
                    viewClient(current);
                    count++;
                }
                current = current->next;
            }
            cout << endl <<(count == 0? RED : GREEN) << "Busqueda terminada " << "[" << count <<"]" NC<< endl;
            _getch();
            break;

        case 3:
            system("cls");
            cout << BLUE "\t BUSQUEDA POR DIRECCION" NC<< endl;
            cout << "Introduce la direccion >> ";
            getline(cin, address);
            while(current != NULL) {
                if(current->address == address ) {
                    viewClient(current);
                    count++;
                }
                current = current->next;
            }
            cout << endl <<(count == 0? RED : GREEN) << "Busqueda terminada " << "[" << count <<"]" NC<< endl;
            _getch();
            break;
        
        case 0:
            break;

        default:
            cout << " " << REDB "La opcion no existe" NC;
            _getch();
            break;
        }
    } while(option !=0);
}


void viewClient(Client *client){
    cout << endl << "CLIENTE: " << client->client.name <<endl;
    cout << "DNI:  " << client->client.dni<< endl;
    cout << "ADDRESS: " << client->address << endl;
    cout << "PRECIO: " << client->number << endl;
}