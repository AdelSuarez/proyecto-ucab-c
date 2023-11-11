#include <iostream>
#include<conio.h>

using namespace std;
struct Person{
    long int dni;
    string name;
};

struct Article {
    string code;
    string name;
    float price;
    int stock;

};

struct Client {
    Person client;
    string address;
    long int number;
    Client *next;
};

struct Seller {
    struct Person seller;
    int date_of_admission;
    int commission;
};


void addLCustomer(Client *&, long int, string , string , long int );

int main() {

    Client *LClient = NULL;
    int opt;
    long int dni, number;
    string name, address;

    do {
        system("cls");
        cout << "Opciones: " << endl;
        cout << "1 - insertar en la lista " << endl;
        cout << "2 - Eliminar en la lista " << endl;
        cout << "3 - mostrar la lista " << endl;
        cout << "4 - Buscar en la lista " << endl;
        cout << "0 - Salir " << endl << endl;

        cout << "Introduce la opcion >> ";
        cin >> opt;
        
        switch (opt){
            case 1:
                system("cls");
                cout << "Agregar nuevo cliente" << endl << endl;
                cout << "DNI del cliente: ";
                cin >> dni;

                cout << "Nombre del cliente: ";
                cin >> name;

                cout << "Direccion del cliente: ";
                cin >> address;

                cout << "Numero del cliente: ";
                cin >> number; 
                addLCustomer(LClient, dni, name,  address,number);

                break;
            case 2:

                break;

            case 3:
                break;

            case 4:
                
                break;  
            case 0:
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
        fflush(stdin);
    } while (opt != 0);
    return 0;
}

// void addLCustomer(Customer *&list, long int dni, string name, string address, long int number) {

//     Customer *new_customer = new Customer(); // creada un nuevo nodo para introducirlo en la lista 
//     new_customer->customer.dni= dni;
//     new_customer->customer.name = name;
//     new_customer->address;
//     new_customer->number; // introduce el dato en le nuevo dato ya creado

//     Customer *aux1 = list;
//     Customer *aux2;

//     while((aux1 != NULL) && (aux1->customer.dni < dni)){
//         aux2 = aux1;
//         aux1 = aux1->next;

//     }

//     if (list == aux1){
//         list = new_customer;

//     } else {
//         aux2->next = new_customer;
//     }


//     new_customer->next = aux1;
//     cout << "agregado con exito";
// }

// void addLCustomer(Customer *&list, long int dni, string name, string address, long int number) {
//     Customer *new_customer = new Customer(); // Create a new node to introduce into the list 
//     new_customer->customer.dni = dni;
//     new_customer->address = address;
//     new_customer->number = number;
//     new_customer->customer.name = name; // Introduce the data into the new node

//     if (list == NULL || list->customer.dni >= dni) { // Insert at the beginning or when list is NULL
//         new_customer->next = list;
//         list = new_customer;
//     } else {
//         Customer *current = list;
//         while (current->next != NULL && current->next->customer.dni < dni) { // Traverse the list to find insertion point
//             current = current->next;
//         }
//         new_customer->next = current->next; // Insert the node
//         current->next = new_customer;
//     }
//     cout << "agregado con exito";
//     getch();

// }

void addLCustomer(Client *&list, long int dni, string name, string address, long int number) {
    Client *new_customer = new Client(); // Create a new node to introduce into the list 
    new_customer->client.dni = dni;
    new_customer->client.name = name;
    new_customer->address = address; // Assign address to new_customer
    new_customer->number = number; // Assign number to new_customer

    if (list == NULL || list->client.dni >= dni) { // Insert at the beginning or when list is NULL
        new_customer->next = list;
        list = new_customer;
    } else {
        Client *current = list;
        while (current->next != NULL && current->next->client.dni < dni) { // Traverse the list to find insertion point
            current = current->next;
        }
        new_customer->next = current->next; // Insert the node
        current->next = new_customer;
    }
    cout << "agregado con exito";
    getch();
}
