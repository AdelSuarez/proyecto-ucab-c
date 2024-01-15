#include <iostream>
#include <iomanip>   
#include <string>
#include <limits>
#include "model/validation.h"
#include "model/node.h"
#include "model/struct.h"
#include "model/bill.h"
#include "model/seller.h"
#include "model/clients.h"
#include "model/articles.h"
#include "file.h"
#include <conio.h>
#include "settings/style.h"
using namespace std;

// List------------------
Client *LClient = NULL;
Article *LArticles = NULL;
Seller *LSeller = NULL;
SalesCheck *LCheck = NULL;

// variables----------------
bool loadingArticles = true;
long long int number, dni;
long int keyArticles, stock, isKey, counterCLient, counterSeller;
float price;
string name, address, code , nameDB;
int opt;

void menuSeller();
void menuClient();
void buys();
void newClient();

int main() {
    readFileArticle(LArticles, keyArticles, DBArticles, false);
    readFileClient(LClient, counterCLient);
    readFileSeller(LSeller, counterSeller);

    createFile("ARTICULOS",DBArticles);
    createFile("CLIENTES",DBClients);
    createFile("VENDEDORES",DBSellers);
    createFile("FACTURA",DBSelesCheck);


    do{
        fflush(stdin);

        system("cls");
        if (loadingArticles){
            cout << "CARGANDO BD..." << endl;  
            cout << "ARTICULOS" << (keyArticles == 0? RED : GREEN) <<"["<< keyArticles << "]" NC << " | " << "VENDEDORES" << (counterSeller == 0? RED : GREEN) <<"["<< counterSeller << "]" NC << " | " << "CLIENTES" <<(counterCLient == 0? RED : GREEN) <<"["<< counterCLient << "]" NC<<endl << endl;
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
        cout << "13 - compra " << endl;

        cout << "0 - Salir " << endl<< endl;

        opt = validateNumber("Introduce la opcion >> ");
        
        switch (opt){
            case 1:
                // add article
                system("cls");
                cout << BLUE "\t-INGRESAR NUEVO ARTICULO-" NC<< endl;

                code = isVoid("Introduce el codigo >> ");
                name = isVoid("Introduce el nombre >> ");
                price = validateNumber("Introduce el precio >> ");
                stock = validateNumber("Introduce el stock >> ");
                keyArticles++;  

                addNode(LArticles, createArticle( keyArticles, code, name, price, stock), false);
                fileUploadArticle(LArticles);
                _getch();
                
                break;
            case 2:
                // edit article
                system("cls");
                if (LArticles != NULL){
                    cout << BLUE "\t-EDITAR ARTICULO-" NC<< endl;
                    isKey = validateNumber(" Introduce la clave >> ");

                    Article *previous = NULL;
                    Article *current = findArticle(LArticles, isKey, previous);


                    if(current != NULL){
                        editArticle(LArticles, isKey, fileUploadArticle);
                    } else{
                        cout << REDB " Articulo no existe!" NC;
                        _getch();
                    }
                } else {
                    cout << REDB "Lista vacia." NC;
                    _getch(); 
                }
                break;

            case 3:
                // Remove article 
                fflush(stdin);
                system("cls");
                cout << BLUE "\t-ELIMINAR ARTICULO- " NC<< endl;
                
                if (LArticles != NULL) {
                    isKey = validateNumber(" Introduce la clave >> ");
                    removeArticles(LArticles, isKey);
                    fileUploadArticle(LArticles);
                } else {
                    cout << REDB "Lista vacia." NC;
                    _getch();
                }
                break; 

            case 4:
                // search article
                system("cls");

                if (LArticles != NULL){
                    searchMenu(LArticles);

                } else {
                    cout << REDB "Lista vacia." NC;
                    _getch();
                }
                break;
            case 5:

                // Add stock
                system("cls");
                cout << BLUE "\t-INGRESO DE STOCK- " NC<< endl; 
                nameDB = isVoid("Introduce el nombre del archivo >> ");
                readFileArticle(LArticles, keyArticles, "db/"+nameDB+".txt", true);
                break;

            case 6:
                //Show articles
                showArticles(LArticles);
                break;

            case 8:
                // MENU CLIENT
                menuClient();
                break;

            case 12:
                // MENU SELLER
                menuSeller();
                break;
            case 13:
                buys();
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
        cout << BLUE "\t-GESTION DE CLIENTES-" NC<< endl;
        cout << "1 - Agregar cliente " << endl;
        cout << "2 - Editar cliente " << endl;
        cout << "3 - Buscar cliente " << endl;
        cout << "4 - Eliminar cliente " << endl;
        cout << "5 - Mostar lista de clientes" << endl;
        cout << "0 - Salir " << endl << endl;

        opt = validateNumber("Introduce la opcion >> ");

        
        switch (opt){
            case 1:
                // ADD CLIENT 
                system("cls");
                newClient();
                break;
            case 2:
                system("cls");
                if (LClient != NULL){
                    cout <<BLUE "\t-EDITAR CLIENTE-" NC<< endl;
                    dni = validateNumber("DNI del cliente: ");

                    editClient(LClient, dni, fileUploadCLient);

                } else {
                    cout << REDB "Lista vacia." NC;
                    _getch(); 
                }
                break; 

            case 3:
                system("cls");
                if (LClient != NULL) {

                    searchMenu(LClient);

                } else {
                    cout << REDB "Lista vacia." NC;
                    _getch(); 
                }
                break; 
                

            case 4:
                system("cls");
                cout <<BLUE "\t-ELIMINAR CLIENTE-" NC<< endl;
                fflush(stdin);
                dni = validateNumber("DNI del cliente >> ");
                removeClient(LClient, dni);
                fileUploadCLient(LClient);
                break;

            case 5:
                showClients(LClient);
                break;

            case 0:
                break;
            default:
                cout << " " << REDB "Opcion no valida" NC;
                _getch();
                break;
            }
    }while (opt != 0);

}


void newClient(){
    bool rDNI;
    fflush(stdin);
    cout << BLUE "\t-AGREGAR NUEVO CLIENTE-" NC << endl;
    while(true) {
        dni = validateNumber("DNI del cliente >> ");
        rDNI = isDuplicate(LClient, dni);
        if (rDNI){
            cout << " " << REDB "Ya existe el DNI" NC << endl;
        } else {
            break;
        }
    }
    fflush(stdin);
    name = isVoid("Nombre del cliente >> ");
    fflush(stdin);
    address = isVoid("Direccion del cliente >> ");
    fflush(stdin);
    number = validateNumber("Numero telefonico del cliente >> ");                
    addClient(LClient, createClient(dni, name,  address, number),false, fileUploadCLient);
    _getch();
}


void menuSeller(){
    int opt, day, month, year, comission;
    do {
        fflush(stdin);

        system("cls");
        cout << BLUE "\t-GESTION DE VENDEDORES-" NC<< endl;
        cout << "1 - Agregar vendedor " << endl;
        cout << "2 - Editar vendedor " << endl;
        cout << "3 - Buscar vendedor " << endl;
        cout << "4 - Eliminar vendedor " << endl;
        cout << "5 - Mostar lista de vendedores" << endl;
        cout << "0 - Salir " << endl << endl;

        opt = validateNumber("Introduce la opcion >> ");

        switch (opt) {
            case 1:
                // ADD SELLER
                bool rDNI;
                system("cls");
                fflush(stdin);
                cout << BLUE "\t-AGREGAR NUEVO VENDEDOR-" NC << endl;
                while(true){
                    dni = validateNumber("DNI del vendedor >> ");
                    rDNI = isDuplicate(LSeller, dni);
                    if(rDNI){
                        cout << " " << REDB "Ya existe el DNI" NC << endl;
                    } else {
                        break;
                    }

                }

                fflush(stdin);
                cout << "Nombre del vendedor >> ";
                getline(cin, name);

                fflush(stdin);
                cout << "-Fecha de admision: "<<endl;
                do {
                    day = validateNumber("Dia >> ");
                    validateDate(day, limiteDay);
                } while (day > limiteDay || day == 0);
                do {
                    month = validateNumber("Mes >> ");
                    validateDate(month, limiteMonth);
                } while( month > limiteMonth || month == 0);
               do {
                    year = validateNumber("Año >> ");
                    validateYear(year, limiteYear);
               } while (year < limiteYear || year == 0);



                comission = validateNumber("Comision del vendedor >> ");

                addNode(LSeller, createSeller(dni, name,  day, month, year,comission),false);
                fileUploadSeller(LSeller);
                _getch();

                break;
            
            case 2:
                system("cls");
                fflush(stdin);
                cout << BLUE "\t-EDITAR VENDEDOR-" NC << endl;

                dni = validateNumber("DNI del vendedor >> ");
                editSeller(LSeller, dni, fileUploadSeller);
                break;

            case 3:
                searchMenu(LSeller);
                break;


            case 4:
                system("cls");
                cout <<BLUE "\t-ELIMINAR VENDEDOR-" NC<< endl;
                fflush(stdin);
                dni = validateNumber("DNI del vendedor >> ");
                removeSeller(LSeller, dni);
                fileUploadSeller(LSeller);
                break;
            case 5:
                showSellers(LSeller);
                break;
            case 0:
                break;  

            default:
                cout << " " << REDB "Opcion no valida" NC;
                _getch();
                break;
            }


    } while (opt != 0);
}

void buys(){
    Article *LBuys = NULL;
    int key;
    long double monto;
    Seller *previousSeller = NULL;
    Client *previousClient = NULL;
    Article *previousArticles = NULL;

    do {
        fflush(stdin);
        system("cls");
        cout << BLUE "\t-COMPRA-" NC<< endl;

        dni = validateNumber("DNI Vendedor >> ");
        Seller *currentSeller = find(LSeller, dni, previousSeller);

        if (currentSeller == NULL) {
            cout << REDB "No existe el vendedor" NC;
            _getch();
            break;
        }
        cout << "VENDEDOR [ " << currentSeller->person.name << " ]" << endl<< endl;

        fflush(stdin);
        dni = validateNumber("DNI Comprador >> ");
        Client *currentClient = find(LClient, dni, 
        previousClient);

        if (currentClient == NULL){
            cout << REDB "\tComprador no registrado" NC << endl;
            newClient();
            currentClient = find(LClient, dni, previousClient);
        }
        while(true){
            int countArticle;
            long double priceCurrent = 0;
            system("cls");
            cout << BLUE "\t-COMPRA-" NC<< endl;
            cout << "VENDEDOR >> " << currentSeller->person.name  << endl;
            cout << "CLIENTE >> " << currentClient->person.name << endl;
            cout << BLUE "\t-ARTICULOS-" NC<< endl;
            if(LBuys != NULL){
                Article *current = LBuys;
                while(current != NULL){
                cout << current->stock<< setw(7) << setw(10) << current->name << setw(7) << current->price << setw(5)<< "$" << endl;
                if (current->stock > 1){
                    priceCurrent += (current->stock * current->price);

                } else {
                    priceCurrent += current->price;

                }
                current = current->next;
                } 
            }
            cout << "-------------------------" << endl;            
            cout << "MONTO >> " << priceCurrent << endl;
            cout << "> Presione 00 para monto total" << endl;
            key = validateNumber("Codigo >> ");
            Article *currentArticle = findArticle(LArticles, key, previousArticles);
            if ( key != 00){
                if ( currentArticle == NULL) {
                    cout << REDB "EL articulos no existe" NC;
                    _getch();
                } else {

                    countArticle = searchArticle(LBuys, "name", currentArticle->name, true);

                    if (countArticle == 0){
                        addNode(LBuys, createArticle(currentArticle->key, currentArticle->code, currentArticle->name, currentArticle->price, (countArticle == 0 ? 1 : countArticle)), true );
                    } else {
                        Article *currentArticle = findArticle(LBuys, key, previousArticles);
                        currentArticle->stock = currentArticle->stock + 1;
                    }
                }
            } else {
                monto = priceCurrent;
                break;
            }
        }
        addNode(LCheck, createBill(1, currentSeller, currentClient, LBuys, 10, monto, 10), false);
        fileUploadCheck(LCheck);


        _getch();
        break;

    } while(opt != 0);
}
