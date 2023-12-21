#include <functional>
using namespace std;

// FIND ARTICLE (SEARCH) ---------------------------------------------------
Article* findArticle(Article *&list, int key, Article *&previous) {
    Article *current = list;
    previous = NULL;

    while (current != NULL && current->key != key) {
        previous = current;
        current = current->next;
    }

    return current;
}


// CREATE ARTICLE -----------------------------------------------
Article* createArticle(long int key, string code, string name, float price, long int stock){
    Article *article = new Article();
    article->key = key;
    article->code = code;
    article->name = name;
    article->price = price;
    article->stock = stock;
    article->next = NULL;
    return article;
}

// EDIT ARTICLE -------------------------------
void editArticle(Article *&list, int long key, void (*fileUploadFunc)(Article *&) ){
    bool isName = false, isCode = false, isPrice = false, isStock = false;
    int option;
    long int newStock;

    Article *previous = NULL;
    Article *current = findArticle(list, key, previous);

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

        option = validateNumber("Introduce la opcion >> ");

        switch (option){
            case 1:
                cout << endl;
                cout << "+\tEditar nombre" << endl;
                current->name = isVoid("| Nuevo nombre: ");
                cout << "|" <<endl;
                cout << "+ "<<GREEN "Nombre editado con exito!" NC;
                isName = true;
                fileUploadFunc(list);

                _getch();
                break;

            case 2:
                cout << endl;
                cout << "+\tEditar codigo" << endl;
                current->code = isVoid("| Nuevo codigo >> ");
                cout << "|" <<endl;
                cout << "+ "<<GREEN "Codigo editado con exito!" NC;
                isCode = true;
                fileUploadFunc(list);

                _getch();
                break;

            case 3:
                cout << endl;
                cout << "+\tEditar price" << endl;
                current->price = validateNumber("| Nuevo precio >> ");
                cout << "|" <<endl;
                cout << "+ "<<GREEN "Precio editado con exito!" NC;
                isPrice = true;
                fileUploadFunc(list);
                _getch();
                break;

            case 4:
                cout << endl;
                cout << "+\tEditar stock" << endl;
                do {
                    newStock = validateNumber("| Nuevo stock >> ");
                } while (newStock < 1);
                current->stock = newStock;
                cout << "|" <<endl;
                cout << "+ "<<GREEN "Stock editado con exito!" NC;
                isStock = true;
                fileUploadFunc(list);
                _getch();
                break;

            case 0:
                break;
            default:
                cout << REDB "La opcion no existe" NC;
                _getch();
                break;
        }
    } while(option !=0);
}

// SHOW ARTICLES -------------------
void showArticles(Article *&list) {
    system("cls");

    Article *current = new Article();
    current = list;

    cout <<BLUE "\t\t\t-LISTA ARTICULOS-" NC<< endl;
    if (list != NULL) {
        cout << BLACK BLUEB ;
        cout << left << setw(10) <<"KEY" << setw(15) << "CODE" << setw(20) << "NOMBRE" << setw(12) << "PRECIO" << setw(7) << "STOCK" << endl;
        cout << NC;

        while(current != NULL){
            cout << left << setw(10) << current->key << setw(12) << current->code << setw(23) << current->name << setw(7) << current->price << setw(5)<< "$" << setw(7) << current->stock << endl;
            current = current->next;
        } 
    } else {
        cout << REDB "La lista de articulos esta vacia" NC;
    }
    cout << endl;
    cout << "Presione cualquier tecla para continuar";
    _getch();
}

// SEARCH ARTICLE -----------------
void viewArticle(Article *);
void searchArticle(Article *list){
    string name;
    float price;
    int option, count;
    long int stock;
    Article* listComplete = list;
    Article* current = list;
    
    do{
        system("cls");
        count = 0;
        cout << BLUE "\t-BUSCAR ARTICULO- " NC<< endl;
        cout << "1- Nombre" << endl;
        cout << "2- Precio" << endl;
        cout << "3- Stock" << endl;
        cout << "0- salir" << endl;


        option = validateNumber("Introduce la opcion >> ");
        cin.ignore();

        switch (option){
            case 1:
                system("cls");
                cout << BLUE "\t BUSQUEDA POR NOMBRE" NC<< endl;
                name = isVoid("Introduce el nombre >> ");
                while(current != NULL) {
                    if(current->name == name ) {
                        viewArticle(current);
                        count++;
                    }
                    current = current->next;
                }
                cout << endl <<(count == 0? RED : GREEN) << "Busqueda terminada " << "[" << count <<"]" NC<< endl;
                _getch();
                break;
            case 2:
                system("cls");
                cout << BLUE "\t BUSQUEDA POR PRECIO" NC<< endl;
                price = validateNumber("Introduce el precio >> ");
                while(current != NULL) {
                    if(current->price == price ) {
                        viewArticle(current);
                        count++;
                    }
                    current = current->next;
                }
                cout << endl <<(count == 0? RED : GREEN) << "Busqueda terminada " << "[" << count <<"]" NC<< endl;
                _getch();
                break;

            case 3:
                system("cls");
                cout << BLUE "\t BUSQUEDA POR STOCK" NC<< endl;
                stock = validateNumber("Introduce el stock >> ");
                while(current != NULL) {
                    if(current->stock == stock ) {
                        viewArticle(current);
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
        current = listComplete;

    } while(option != 0);
}
void viewArticle(Article *article){
    cout << endl << "ARTICULO: " << article->name <<endl;
    cout << "CLAVE:  " << article->key << endl;
    cout << "CODIGO: " << article->code << endl;
    cout << "PRECIO: " << article->price << endl;
    cout << "STOCK:  " << article->stock << endl;
}


// REMOVE ARTICLE ------------------------------
void removeArticles(Article *&list, int long key){
    string opt;
    Article *previous = NULL;
    Article *current = findArticle(list, key, previous);

    if(current != NULL){
        fflush(stdin);
        cout << "Articulo: " << current->name << endl;
        opt = isVoid("Desea eliminar el articulo (s/n) >> ");
        if ((opt == "s") || (opt == "S")){
            removeNode(list,current, previous);
        } else {
            return;
        }

    } else {
        cout << REDB " El articulo no existe!" NC;
        _getch();
    }

}
