#include <iostream>
#include <string>
#include <limits>
#include"model/clients.h"
#include"model/articles.h"
#include"file.h"

#include<conio.h>

using namespace std;

Client *LClient = NULL;
Article *LArticles = NULL;

bool loadingArticles = true;
long long int number, dni;
long int key, stock;
float price;
string name, address, code;
int opt;


void menuClient();

int main() {
    readFile(LArticles, key);
    createFile();
    
    do{
        fflush(stdin);

        system("cls");
        if (loadingArticles){
            cout << "> Se han cargado los articulos -> " GREEN << key<< "" NC<<endl << endl;
            loadingArticles = false;
        }
        

        cout << BLUE "\t-TIENDA DE ARTICULOS-" NC << endl;
        cout << "1 - Ingresar nuevo articulo " << endl;
        cout << "2 - Editar articulo " << endl;
        cout << "3 - Eliminar articulo" << endl;
        cout << "4 - Busqueda de Articulos" << endl;
        cout << "5 - Ingreso de Stock al Inventario" << endl;
        cout << "6 - Ver Articulos " << endl << endl;
        
        cout << "7 - Menu Gestion de Facturas " << endl;
        cout << "8 - Menu Gestion de Clientes " << endl;
        cout << "9 - Menu Gestion de Descuentos " << endl;
        cout << "10 - Menu Gestion de Bonos " << endl;
        cout << "11 - Menu Gestion de Comisiones " << endl;
        cout << "12 - Menu Gestion de Vendedores " << endl;

        cout << "0 - Salir " << endl;
        cout << "V0.0.1.5 " << endl << endl;

        // cout << "Introduce la opcion >> ";
        // cin >> opt;
        opt = validateNumber("Introduce la opcion >> ");
        cin.ignore();

        
        switch (opt){
            case 1:
                // add article
                system("cls");
                cout << BLUE "\t-INGRESAR NUEVO ARTICULO-" NC<< endl;
                cout << "Introduce el codigo >> ";
                getline(cin, code);
                cout << "Introduce el nombre >> ";
                getline(cin, name);
                cout << "Introduce el precio >> ";
                cin >> price;

                cout << "Introduce el stock >> ";
                cin >> stock;
                key++;

                addArticle(LArticles, creatArticle( key, code, name, price, stock), false);
                fileUpload(LArticles);
                
                break;
            case 2:
                system("cls");

                // edit article
                if (LArticles != NULL){
                    cout << BLUE "\t-EDITAR ARTICULO-" NC<< endl;
                    cout << "Introduce el nombre: ";
                    getline(cin, name);


                    if(search(LArticles, name)){
                        editArticle(LArticles, name);
                        fileUpload(LArticles);
                        cout << GREEN "Articulo editado con exito!" NC;
                        _getch();
                    } else{
                        cout << " Articulo no existe!"<< endl;
                        cout << "Presione un boton para continuar.";
                        _getch();
                    }
                } else {
                    cout << "No existen articulos. Presione un boton para continuar";
                    _getch(); 
                }
                break;

            case 3:
                system("cls");
                cout << BLUE "\t-ELIMINAR ARTICULO- " NC<< endl;
                
                if (LArticles != NULL) {
                    cout << "Introduce el nombre: ";
                    getline(cin, name);
                    removeArticles(LArticles, name);
                    fileUpload(LArticles);
                } else {
                    cout << "No existen articulos. Presione un boton para continuar";
                    _getch();
                }
                break; 

            case 4:

                system("cls");

                if (LArticles != NULL){
                    searchArticle(LArticles);

                } else {
                    cout << "No existen articulos. Presione un boton para continuar";
                    _getch();
                }
                break;
            case 6:
                showArticles(LArticles);
                break;

            case 8:
                // MENU CLIENT
                menuClient();
                break;
            case 0:
                break;
            default:
                cout << " " << REDB "Opcion no valida" NC;
                _getch();
                break;
            }
    }while (opt != 0);
    return 0;
}

void menuClient(){
    int opt;
    do{
        fflush(stdin);

        system("cls");
        cout << "\t-GESTION DE CLIENTES-" << endl;
        cout << "1 - Agreagar un cliente nuevo " << endl;
        cout << "2 - Editar cliente " << endl;
        cout << "3 - Buscar cliente " << endl;
        cout << "4 - Eliminar cliente " << endl;
        cout << "5 - Mostar lista de clientes" << endl;
        cout << "0 - Salir " << endl << endl;

        cout << "Introduce la opcion >> ";
        cin >> opt;
        cin.ignore();

        
        switch (opt){
            case 1:
                system("cls");
                fflush(stdin);
                
                cout << "\t-Agregar nuevo cliente-" << endl << endl;
                cout << "DNI del cliente: ";
                cin >> dni;
                cin.ignore();

                fflush(stdin);
                cout << "Nombre del cliente: ";
                getline(cin, name);

                fflush(stdin);
                cout << "Direccion del cliente: ";
                getline(cin, address);

                fflush(stdin);
                cout << "Numero telefonico del cliente: ";
                cin >> number; 
                cin.ignore();

                cout << name << " " << address << " " << number << " " << dni<< endl;
                addLClient(LClient, dni, name,  address, number);
                _getch();

                break;
            case 2:
                system("cls");
                cout << "\t-Editar cliente-" << endl;
                cout << "DNI del cliente: ";
                cin >> dni;
                cin.ignore();

                editClient(LClient, dni);
                break; 

            case 3:
                system("cls");
                cout << "\t-Buscar cliente-" << endl;

                fflush(stdin);
                cout << "DNI del cliente: ";
                cin >> dni;

                
                fflush(stdin);
                cout << "nombre del cliente: ";
                getline(cin, name);

                // cout << "Direccion del cliente: ";
                // getline(cin, address);


                searchClient(LClient, dni, name);
                break; 
                

            case 4:
                cout << "\t-Eliminar cliente" << endl;
                cout << "Nombre del cliente: ";
                getline(cin, name);

                removeClient(LClient, name);
                break;

            case 5:
                showClients(LClient);
                break;
            case 0:
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
    }while (opt != 0);

}