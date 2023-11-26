#include <iostream>
#include<string>
#include <iomanip>
#include<conio.h>
#include <functional>
#include"../settings/style.h"


using namespace std;

// STRUCT OF ARTICLE
struct Article {
    long int key;
    string code;
    string name;
    float price;
    long int stock;
    Article *next;
};


// SEARCH ARTICLE ------------------------
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

// CREATE ARTICLE -----------------------------------------------
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

// ADD ARTICLE ------------------------------------------------
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
        cout << GREEN "\tAgregado con exito" NC << endl << endl;
        cout << "Presiona cualquier boton para continuar ";

        getch();
    }
    
}


// EDIT ARTICLE -------------------------------
void editArticle(Article *&list, string name ){
    bool isName = false, isCode = false, isPrice = false, isStock = false;
    int option;
    long int newStock;
    float newPrice;
    string newName, newCode;

    Article *current = list;
    while(current != NULL && current->name != name){
        current = current->next;
    }
    do {
        system("cls");
        fflush(stdin);
        cout << BLUE "\t-OPCIONES-" NC<< endl;
        cout << left << setw(1)<<"Clave "<< setw(5) << current->key  <<"| ARTICULO"<< endl;
        cout << left << setw(1) << "1-" << setw(9) << "Nombre"<< "| " << setw(12) << current->name << (isName ? GREEN "*" NC: "") << endl;
        cout << left << setw(1) << "2-" << setw(9) << "Codigo"<< "| " << setw(12) << current->code << (isCode ? GREEN "*" NC: "") << endl;
        cout << left << setw(1) << "3-" << setw(9) << "Precio"<< "| " << setw(12) << current->price << (isPrice ? GREEN "*" NC: "") << endl;
        cout << left << setw(1) << "4-" << setw(9) << "Stock"<< "| " << setw(12) << current->stock << (isStock ? GREEN "*" NC: "") << endl;
        cout << "0- Salir" << endl;
        cout << "Introduce la opcion >> ";
        cin >> option;
        cin.ignore();
        cout << endl;

        switch (option){
        case 1:
            cout << "+\tEditar nombre" << endl;
            cout << "| Nuevo nombre: ";
            getline(cin, newName);
            current->name = newName;
            cout << "|" <<endl;
            cout << "+ Nombre editado con exito!";
            isName = true;

            getch();
            break;

        case 2:
            cout << "+\tEditar codigo" << endl;
            cout << "| Nuevo codigo >> ";
            getline(cin, newCode);
            current->code = newCode;
            cout << "|" <<endl;

            cout << "+ Codigo editado con exito!";
            isCode = true;
            getch();
            break;

        case 3:
            cout << "+\tEditar price" << endl;
            cout << "| Nuevo precio >> ";
            cin >> newPrice;
            current->price = newPrice;
            cout << "|" <<endl;
            cout << "+ Precio editado con exito!";
            isPrice = true;
            getch();
            break;

        case 4:
            cout << "+\tEditar stock" << endl;
            cout << "| Nuevo stock >> ";
            cin >> newStock;
            current->stock = newStock;
            cout << "|" <<endl;
            cout << "+ Stock editado con exito!";
            isStock = true;
            
            getch();
            break;

        case 0:
            break;
        default:
            cout << " " << REDB "La opcion no existe" NC;
            getch();
            break;
        }
    } while(option !=0);
}

// SHOW ARTICLES -------------------
void showArticles(Article *&list) {
    system("cls");

    Article *current = new Article();
    current = list;

    if (list != NULL) {
        cout <<BLUE "\t\t\t-LISTA ARTICULOS-" NC<< endl;
        cout << BLACK BLUEB ;
        cout << left << setw(10) <<"KEY" << setw(15) << "CODE" << setw(20) << "NOMBRE" << setw(12) << "PRECIO" << setw(7) << "STOCK" << endl;
        cout << NC;

            while(current != NULL){
                cout << left << setw(10) << current->key << setw(12) << current->code << setw(23) << current->name << setw(7) << current->price << setw(5)<< "$" << setw(7) << current->stock << endl;
                current = current->next;
            //     cout << "  " << current->key << "  | " << current->code << "  | " << current->name << " | " << current->price << " | " << current->stock <<endl;
            //     current = current->next;
            } 
        // } else {
        //     cout << "La lista de articulos esta vacia";
        //     // list = NULL;
        // }
    } else {
        cout << "La lista de articulos esta vacia";
    }
    cout << endl;
    cout << "Presione cualquier tecla para continuar";
    getch();
}

void remove(Article *&, string);

void viewArticle(Article *article){
    cout << endl << "ARTICULO: " << article->name <<endl;
    cout << "CLAVE:  " << article->key << endl;
    cout << "CODIGO: " << article->code << endl;
    cout << "PRECIO: " << article->price << endl;
    cout << "STOCK:  " << article->stock << endl;

}

void searchArticle(Article *list){
    string name;
    float price;
    int option, count;
    long int stock;
    Article* current = list;
    
    
    
    do{
        system("cls");
        count = 0;
        cout << BLUE "\t-BUSCAR ARTICULO- " NC<< endl;
        cout << "1- Nombre" << endl;
        cout << "2- Precio" << endl;
        cout << "3- Stock" << endl;
        cout << "0- salir" << endl;
        cout << "Introduce la opcion >> ";

        cin >> option;
        cin.ignore();

        switch (option){
            case 1:
                system("cls");
                cout << BLUE "\t BUSQUEDA POR NOMBRE" NC<< endl;
                cout << "Introduce el nombre >> ";
                getline(cin, name);
                while(current != NULL) {
                    if(current->name == name ) {
                        viewArticle(current);
                        count++;
                    }
                    current = current->next;
                }
                cout << endl <<(count == 0? RED : GREEN) << "Busqueda terminada " << "[" << count <<"]" NC<< endl;
                getch();
                break;
            case 2:
                system("cls");
                cout << BLUE "\t BUSQUEDA POR PRECIO" NC<< endl;
                cout << "Introduce el precio >> ";
                cin >> price;
                while(current != NULL) {
                    if(current->price == price ) {
                        viewArticle(current);
                        count++;
                    }
                    current = current->next;
                }
                cout << endl <<(count == 0? RED : GREEN) << "Busqueda terminada " << "[" << count <<"]" NC<< endl;
                getch();
                break;

            case 3:
                system("cls");
                cout << BLUE "\t BUSQUEDA POR STOCK" NC<< endl;
                cout << "Introduce el stock >> ";
                cin >> stock;
                while(current != NULL) {
                    if(current->stock == stock ) {
                        viewArticle(current);
                        count++;
                    }
                    current = current->next;
                }
                cout << endl <<(count == 0? RED : GREEN) << "Busqueda terminada " << "[" << count <<"]" NC<< endl;
                getch();
                break;

            case 0:
                break;

            default:
                cout << " " << REDB "La opcion no existe" NC;
                getch();
                break;
        } 


    } while(option != 0);
}




void removeArticles(Article *list, string name){
    string opt;

    if(search(list, name)){
        
        cout << "Articulo: "<< name << endl;
        cout << "Desea eliminar el articulo (s/n) >> ";
        getline(cin, opt);
        if ((opt == "s") ||(opt == "S")){
            remove(list, name);
        } else {
            return;
        }

    } else {
        cout << "\t El articulo no existe!" << endl;
    }
    getch();

}

void remove(Article *&list, string name) {
    Article *current = list;
    Article *previous = NULL;

    while (current != NULL && current->name != name) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "El artículo no se encontró en la lista." << endl;
        return;
    }

    if (previous == NULL) { // El artículo a eliminar es el primer elemento
        list = current->next;
    } else { // El artículo a eliminar está en medio o al final de la lista
        previous->next = current->next;
    }
    delete current;
    showArticles(list);

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

