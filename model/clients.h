using namespace std;

// CREATE CLIENT ---------------------------------------------------------------------
Client* createClient(long long int dni, string name, string address, long long int number){
    Client *client = new Client();
    client->person.dni = dni;
    client->person.name = name;
    client->address = address;
    client->number = number;
    client->next = NULL;
    return client;
}


// ADD CLIENT ---------------------------------------------------------------------
void addClient(Client *&list, Client *client, bool isFile, void (*fileUploadFunc)(Client *&) ) {
    Client *current = list;

    if (list == NULL || current->person.dni >= client->person.dni) {
        client->next = list;
        list = client;
    } else {
        while (current->next != NULL && current->next->person.dni < client->person.dni) {
            current = current->next;
        }
        client->next = current->next;
        current->next = client;
    }

    if (!isFile){
        cout << BLACK GREENB "Agregado con exito" NC;

    }
    fileUploadFunc(list);
}

void showClients(Client *list) {
    system("cls");

    Client *current = new Client();
    current = list;

    cout <<BLUE "\t\t\t\t-LISTA CLIENTES-" NC<< endl;
    cout << BLACK BLUEB ;
    cout << left << setw(15) << "DNI" << setw(30) << "NOMBRE" << setw(30) << "DIRECCION" << setw(12) << "NUMERO" << endl;
    cout << NC;
    while(current != NULL){
        cout << left << setw(15) << current->person.dni << setw(30) << current->person.name << setw(30) << current->address << setw(12) << current->number << endl;
        current = current->next;
    }
    cout << endl;
    cout << "Presione cualquier tecla para continuar";
    _getch();
}

void removeClient(Client *&list, long long int dni){
    string option;
    Client *previous = NULL;
    Client *current = find(list, dni, previous);

    if (current != NULL){
        fflush(stdin);
        cout << "Cliente: " << current->person.name << endl;
        option = isVoid("Desea eliminar el cliente (s/n) >> ");
        if ((option == "s") ||(option == "S")){
            removeNode(list,current, previous);
        } else {
            return;
        }
    } else {
        cout << REDB " El articulo no existe!" NC;
        _getch();
    }

}


void editClient(Client *&list, long long int dni, void (*fileUploadFunc)(Client *&)){
    bool isName = false, isDNI = false, isAddress = false, isNumber = false;
    long long int newDNI, newNumber;
    int option;
    Client *previous = NULL;
    Client *current = find(list, dni, previous);
    if (current != NULL){

        do {
            system("cls");
            fflush(stdin);
            cout << BLUE "\t-OPCIONES-" NC<< endl;
            cout << left << setw(1) << "1-" << setw(12) << "Nombre"<< "| " << setw(15) << current->person.name << (isName ? GREEN "*" NC: "") << endl;
            cout << left << setw(1) << "2-" << setw(12) << "DNI"<< "| " << setw(15) << current->person.dni << (isDNI ? GREEN "*" NC: "") << endl;
            cout << left << setw(1) << "3-" << setw(12) << "Direccion"<< "| " << setw(15) << current->address << (isAddress ? GREEN "*" NC: "") << endl;
            cout << left << setw(1) << "4-" << setw(12) << "Numero"<< "| " << setw(15) << current->number << (isNumber ? GREEN "*" NC: "") << endl;
            cout << "0- Salir" << endl;

            option = validateNumber("Introduce la opcion >> ");

            switch (option){
                case 1:
                    cout << endl;
                    cout << "+\tEditar nombre" << endl;
                    current->person.name = isVoid("| Nuevo nombre: ");
                    cout << "|" <<endl;
                    cout << "+ "<<GREEN "Nombre editado con exito!" NC;
                    isName = true;
                    fileUploadFunc(list);
                    _getch();
                    break;

                case 2:
                    cout << endl;
                    cout << "+\tEditar DNI" << endl;
                    newDNI = validateNumber("| Nuevo DNI >> ");
                    current->person.dni = newDNI;
                    cout << "|" <<endl;
                    cout << "+ "<<GREEN "DNI editado con exito!" NC;
                    isDNI = true;
                    fileUploadFunc(list);
                    _getch();
                    break;

                case 3:
                    cout << endl;
                    cout << "+\tEditar direccion" << endl;
                    current->address = isVoid("| Nueva direccion: ");
                    cout << "|" <<endl;
                    cout << "+ "<<GREEN "Direccion editada con exito!" NC;
                    isAddress = true;
                    fileUploadFunc(list);
                    _getch();
                    break;
                case 4:
                    cout << endl;
                    cout << "+\tEditar numero" << endl;
                    newNumber = validateNumber("| Nuevo numero >> ");
                    current->number = newNumber;
                    cout << "|" <<endl;
                    cout << "+ "<<GREEN "Stock editado con exito!" NC;
                    isNumber = true;
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

        } while(option != 0);
    } else {
        cout << REDB " Articulo no existe!" NC;
        _getch();
    }
}

void viewClient(Client *client){
    cout << endl<<  left << setw(10) << "CLIENTE: " << client->person.name <<endl;
    cout << left << setw(10) << "DNI:  " << client->person.dni<< endl;
    cout << left << setw(10) << "DIRECCION: " << client->address << endl;
    cout << left << setw(10) << "PRECIO: " << client->number << endl;
}

void searchClient(Client* list, string criterion, string value){
    Client* current = list;
    int count = 0;
    while(current != NULL) {
        if((criterion == "name" && current->person.name == value) ||
           (criterion == "dni" && to_string(current->person.dni) == value) ||
           (criterion == "address" && current->address == value)) {
            viewClient(current);
            count++;
        }
        current = current->next;
    }
    cout << endl <<(count == 0? RED : GREEN) << "Busqueda terminada " << "[" << count <<"]" NC<< endl;
    _getch();
}

void searchMenu(Client* list){
    int option;
    string text;
    do {
        system("cls");
        cout << BLUE "\t-BUSCAR ARTICULO- " NC<< endl;
        cout << "1- Nombre" << endl;
        cout << "2- DNI" << endl;
        cout << "3- Direccion" << endl;
        cout << "0- salir" << endl;

        option = validateNumber("Introduce la opcion >> ");

        switch (option){
            case 1:
                system("cls");
                cout << BLUE "\t BUSQUEDA POR NOMBRE" NC<< endl;
                text = isVoid("Introduce el nombre >> ");
                searchClient(list, "name", text);
                break;

            case 2:
                system("cls");
                cout << BLUE "\t BUSQUEDA POR DNI" NC<< endl;
                text = isVoid("Introduce el DNI >> ");
                searchClient(list, "dni", text);
                break;

            case 3:
                system("cls");
                cout << BLUE "\t BUSQUEDA POR DIRECCION" NC<< endl;
                text = isVoid("Introduce la direccion >> ");
                searchClient(list, "address", text);
                break;
            
            case 0:
                break;

            default:
                cout << " " << REDB "La opcion no existe" NC;
                _getch();
                break;
        }
    } while(option !=0);
}
