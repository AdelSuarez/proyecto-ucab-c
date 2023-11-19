#include <iostream>
#include<string>
#include<conio.h>
using namespace std;

struct Article {
    long int key;
    string code;
    string name;
    float price;
    long int stock;
    Article *next;
};



void addArticle(Article *&list, long int key,string code, string name, float price, long int stock){
    Article *newArticle = new Article();
    newArticle->key = key;

    newArticle->code = code;
    newArticle->name = name;
    newArticle->price = price;
    newArticle->stock = stock;
    newArticle->next = NULL;



    if (list == NULL){
        newArticle->next = list;
        list = newArticle;
    } else {
        Article *current = list;
        while(current->next != NULL){
            current = current->next;
        }
        newArticle->next = current->next;
        current->next = newArticle;

    }
    cout << "agregado con exito";
    getch();
    
    // TODO terminar de desarrollar 
}

void showArticles(Article *list) {
    system("cls");


    Article *current = new Article();
    current = list;

    if (list != NULL) {
        cout << "\t-LISTA ARTICULOS-" << endl;
        while(current != NULL){
            cout << current->key << " | " << current->code << " | " << current->name << " | " << current->price << " | " << current->stock <<endl;
            current = current->next;
        } 
    } else {
        cout << "La lista de articulos esta vacia";
    }
    cout << endl;
    cout << "Presione cualquier tecla para continuar";
    getch();
}

void removeStock(Article *&, string);
void remove(Article *&, string);
bool searchArticle(Article *, string);
void removeArticles(Article *list, string name){
    int opt;
    bool found = searchArticle(list, name);

    if(found){
        cout << "1. Eliminar articulo "<< endl;
        cout << "2. Eliminar de stock articulo "<< endl;
        cout << "Introduce la opcion: ";
        cin >> opt;

        switch(opt) {
            case 1:
                system("cls");
                cout << "Eliminar articulo "<< endl;
                remove(list, name);
                break;

            case 2:
                system("cls");
                cout << "Eliminar de stock articulo "<< endl;
                removeStock(list, name);
                break;

            default:
                cout << "La opcion no existe"<< endl;
                break;
        }
        
        // cout << "se puede editar" << endl;

    } else {
        cout << "No se puede editar " << endl;
    }
    getch();

}


bool searchArticle(Article *list , string name){
    Article *current = list;
    bool found = false;

    while(current != NULL && !found) {
        if(current->name == name) {
            cout << " Stock disponible: " << current->stock << endl;
            found = true;
        }

        current = current->next;
    }

    if(!found){
        cout << "Articulo no encontrado" << endl;
    } 

    return found;
}

// TODO verificar porque imprime en consola 0 | | | | 0 al momento de mostrar la lista 
void remove(Article *&list, string name) {
    if ( list != NULL) {
        Article *auxRemove;
        Article *previous = NULL;

        auxRemove = list;

        while((auxRemove != NULL) && (auxRemove->name != name)){
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

void removeStock(Article *&list, string name){
    long int stockToRemove;
    Article *current = list;

        // Buscar el nodo con el DNI proporcionado
    while(current != NULL && current->name != name){
        current = current->next;
    }

    // Si el nodo fue encontrado, modificar sus valores
    if (current != NULL){
        // TODO la funcion no se a probado con este ciclo
        
        do {
            cout << "Introduce la cantidad de productos a eliminar: ";
            cin >> stockToRemove;

        } while(stockToRemove <= current->stock);

        
        current->stock = current->stock - stockToRemove;
        cout << "Modificado con exito";
    }
}

