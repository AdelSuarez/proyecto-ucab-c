#include <iostream>
#include<string>
#include<conio.h>
using namespace std;

struct Person{
    long int dni;
    string name;
};

struct Client {
    Person client;
    string address;
    long int number;
    Client *next;
};

void addLClient(Client *&list, long int dni, string name, string address, long int number) {
    Client *new_client = new Client(); // Create a new node to introduce into the list 
    new_client->client.dni = dni;
    new_client->client.name = name;
    new_client->address = address; // Assign address to new_client
    new_client->number = number; // Assign number to new_client

    if (list == NULL || list->client.dni >= dni) { // Insert at the beginning or when list is NULL
        new_client->next = list;
        list = new_client;
    } else {
        Client *current = list;
        while (current->next != NULL && current->next->client.dni < dni) { // Traverse the list to find insertion point
            current = current->next;
        }
        new_client->next = current->next; // Insert the node
        current->next = new_client;
    }
    cout << "agregado con exito";

}

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