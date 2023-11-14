#include <iostream>
#include<string>
#include<conio.h>
#include "person.h"
using namespace std;

struct Client {
    Person client;
    string address;
    long long int number;
    Client *next;
};


// ! Se produce un error que genera un bucle infinito
void addLClient(Client *&list, long long int dni, string name, string address, long long int number) {
    Client *newClient = new Client(); // Create a new node to introduce into the list 
    newClient->client.dni = dni;
    newClient->client.name = name;
    newClient->address = address; // Assign address to new_client
    newClient->number = number; // Assign number to new_client
    newClient->next = NULL; // Initialize next pointer to NULL


    if (list == NULL || list->client.dni >= dni) { // Insert at the beginning or when list is NULL
        newClient->next = list;
        list = newClient;
    } else {
        Client *current = list;
        while (current->next != NULL && current->next->client.dni < dni) { // Traverse the list to find insertion point
            current = current->next;
        }
        newClient->next = current->next; // Insert the node
        current->next = newClient;
    }
    cout << "agregado con exito";

}

// void addLClient(Client *&list, long int dni, string name, string address, long int number) {
//     Client *newClient = new Client(); // Create a new node to introduce into the list 
//     newClient->client.dni = dni;
//     newClient->client.name = name;
//     newClient->address = address; // Assign address to new_client
//     newClient->number = number; // Assign number to new_client
//     newClient->next = NULL; // Initialize next pointer to NULL

//     if (list == NULL || list->client.dni >= dni) { // Insert at the beginning or when list is NULL
//         newClient->next = list;
//         list = newClient;
//     } else {
//         Client *current = list;
//         while (current->next != NULL && current->next->client.dni < dni) { // Traverse the list to find insertion point
//             current = current->next;
//         }
//         newClient->next = current->next; // Insert the node
//         current->next = newClient;
//     }
//     cout << "agregado con exito";
// }


void showClients(Client *list)
{
    system("cls");
    cout << "Lista" << endl;


    Client *current = new Client();
    current = list;

    while(current != NULL){
        cout << current->client.name << " | " << current->client.dni << " | " << current->address << " | " << current->number <<endl;
        current = current->next;
    }
    cout << endl;
    cout << "Presione cualqueir tecla para continuar";
    getch();
}


void removeClient(Client *&list, string name){
    // TODO Modificar para que omita los espacios y pueda borrar segun lo que se escriba
    if ( list != NULL) {
        Client *auxRemove;
        Client *previous = NULL;

        auxRemove = list;

        while((auxRemove != NULL) && (auxRemove->client.name != name)){
            previous = auxRemove;
            auxRemove = auxRemove->next;
        }

        if (auxRemove == NULL){
            cout << "El elemento no ha sido encontrado";
        } else if(previous == NULL) {
            list = list->next;
            delete auxRemove;
        } else {
            previous->next = auxRemove->next;
            delete auxRemove;
        }
    }
}


void editClient(Client *&list, long long int dni){
    string newName, newAddress;
    long int newNumber;


    if ( list != NULL) {
        Client *current = list;

        // Buscar el nodo con el DNI proporcionado
        while(current != NULL && current->client.dni != dni){
            current = current->next;
        }

        // Si el nodo fue encontrado, modificar sus valores
        if (current != NULL){

            cout << " nuevo Nombre del cliente: ";
            getline(cin, newName);

            cout << "nueva Direccion del cliente: ";
            getline(cin, newAddress);

            cout << "nuevo Numero del cliente: ";
            cin >> newNumber; 
            cin.ignore();

            current->client.name = newName;
            current->address = newAddress;
            current->number = newNumber;
            cout << "Modificado con exito";
        } else {
            // Si el nodo no fue encontrado, imprimir un mensaje
            cout << "El elemento no ha sido encontrado";
            getch();
        }
    }
}
