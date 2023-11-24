#include <iostream>
#include<string>
#include"model/clients.h"
#include"model/articles.h"
#include"file.h"

#include<conio.h>

using namespace std;

Client *LClient = NULL;
Article *LArticles = NULL;


long long int number, dni;
long int key, stock;
float price;
string name, address, code;
int opt;


void menuClient();


int main() {
    createFile();
    do{
        fflush(stdin);

        system("cls");
        cout << "\t-TIENDA DE ARTICULOS-" << endl;
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

        cout << "0 - Salir " << endl << endl;

        cout << "Introduce la opcion >> ";
        cin >> opt;
        cin.ignore();

        
        switch (opt){
            case 1:
                // add article
                system("cls");
                cout << "\tINGRESAR NUEVO ARTICULO-" << endl;
                cout << "Introduce el codigo: ";
                getline(cin, code);
                cout << "Introduce el nombre: ";
                getline(cin, name);
                cout << "Introduce el precio: ";
                cin >> price;

                cout << "Introduce el stock: ";
                cin >> stock;
                key++;
                writeFile(code, name, price, stock);
                addArticle(LArticles, creatArticle( key, code, name, price, stock), false);
                break;
            case 2:
                system("cls");

                // edit article
                cout << "\tEDITAR ARTICULO-" << endl;

                cout << "Introduce el nombre: ";
                getline(cin, name);
                editArticle(LArticles, name);
                break; 

            case 3:
                system("cls");
                cout << "\t-ELIMINAR ARTICULO- "<< endl;
                
                if (LArticles != NULL) {
                    cout << "Introduce el nombre: ";
                    getline(cin, name);
                    removeArticles(LArticles, name);

                } else {
                    cout << "No existen articulos. Presione un boton para continuar";
                    getch();
                }
                break; 
                
            case 6:
                readFile(LArticles);
                showArticles(LArticles);
                break;

            case 8:
                // MENU CLIENT
                menuClient();
                break;
            case 0:
                break;
            default:
                cout << "Opcion no valida" << endl;
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
                getch();

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