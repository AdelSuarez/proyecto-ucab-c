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


Article* creatArticle(long int key, string code, string name, float price, long int stock){
    Article *article = new Article();
    article->key = key;
    article->code = code;
    article->name = name;
    article->price = price;
    article->stock = stock;
    article->next = NULL;
    return article;
}


void addArticle(Article *&list, Article *article, bool isFile){

    if (list == NULL){
        list = article;
    } else {
        Article *current = list;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = article;

    }
    if (!isFile){
        cout << "Agregado con exito"<< endl;
        cout << "Presiona cualquier boton para continuar"<< endl;

        getch();
        // TODO terminar de desarrollar 
    }
    
}

// TODO esta funcion no hace lo que quiero
// Article* currentArticle(Article *&list, string name ){
//     Article *current = list;

//     // Buscar el nodo con el DNI proporcionado
//     while(current != NULL && current->name != name){
//         current = current->next;
//     }
//     return current;
// }

// TODO terminar la funcion
bool search(Article *, string);
void editArticle(Article *&list, string name ){
    int option;
    string newName;
    if (list != NULL){
        if (search(list, name)) {
            Article *current = list;
            // Buscar el nodo con el DNI proporcionado
            while(current != NULL && current->name != name){
                current = current->next;
            }
            do {

                cout << "\tOpciones a editar " << current->name << endl;
                cout << "Clave " << current->key << endl;
                cout << "1- Nombre: " << current->name << endl;
                cout << "2- Codigo: " << current->code << endl;
                cout << "3- Precio: " << current->price << endl;
                cout << "4- Stock: " << current->stock << endl;
                cout << "0- Salir " << endl;
                cout << "Introduce la opcion >> ";
                cin >> option;

                switch (option)
                {
                case 1:
                    cout << "Editar nombre" << endl;
                    cout << "Nuevo nombre: ";
                    getline(cin, newName);
                    current->name = newName;
                    break;
                
                default:
                    cout << "La opcion no existe";
                    break;
                }
            } while(option !=0);

        } else {
            cout << "no encontrado";
        }
        getch();
    }
}




bool search(Article *list , string name){
    Article *current = list;
    bool found = false;

    while(current != NULL && !found) {
        if(current->name == name) {
            found = true;
        }
        current = current->next;
    }
    return found;
}














void showArticles(Article *&list) {
    system("cls");


    Article *current = new Article();
    current = list;

    if (list != NULL) {
        cout << "\t-LISTA ARTICULOS-" << endl;
        if (current->key != 0){

            while(current != NULL){
                cout << current->key << " | " << current->code << " | " << current->name << " | " << current->price << " | " << current->stock <<endl;
                current = current->next;
            } 
        } else {
            cout << "La lista de articulos esta vacia";
            list = NULL;
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

// TODO verificar porque imprime en consola 0 | | | | 0 al momento de mostrar la lista, seguir revisando la funcion
void remove(Article *&list, string name) {
    
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
        // TODO: NO funciona bien esta condicional
        if (list != NULL && list->next == NULL && list->name == "") {
            delete list;
            list = NULL;
        }
    } else {
        previous->next = auxRemove->next;
        delete auxRemove;
        if (previous->next != NULL && previous->next->next == NULL && previous->next->name == "") {
            delete previous->next;
            previous->next = NULL;
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

        } while(stockToRemove >= current->stock);

        
        current->stock = current->stock - stockToRemove;
        cout << "Modificado con exito";
    }
}

