using namespace std;


Seller* findSeller(Seller *&list, long long int dni, Seller *&previous) {
    Seller *current = list;
    previous = NULL;

    while (current != NULL && current->seller.dni != dni) {
        previous = current;
        current = current->next;
    }

    return current;
}


Seller* createSeller(long long int dni, string name, int day, int month, int year, int comission){
    Seller *seller = new Seller();
    seller->seller.dni = dni;
    seller->seller.name = name;
    seller->admissionDay.day = day;
    seller->admissionDay.month = month;
    seller->admissionDay.year = year;
    seller->commission = comission;

    seller->next = NULL;
    return seller;
}

void showSellers(Seller *list) {
    system("cls");

    Seller *current = new Seller();
    current = list;

    cout <<BLUE "\t\t\t\t-LISTA VENDEDORES-" NC<< endl;
    cout << BLACK BLUEB ;
    cout << left << setw(15) << "DNI" << setw(30) << "NOMBRE" << setw(30) << "ADMISION" << setw(12) << "COMISION" << endl;
    cout << NC;
    while(current != NULL){
        cout << left << setw(15) << current->seller.dni << setw(30) << current->seller.name  << current->admissionDay.day<<"/" << current->admissionDay.month<<"/"<< setw(28) << current->admissionDay.year << setw(12) << current->commission << endl;
        current = current->next;
    }
    cout << endl;
    cout << "Presione cualquier tecla para continuar";
    _getch();
}



void editSeller(Seller *&list, long long int dni, void (*fileUploadFunc)(Seller *&)){
    int option;
    bool isName = false, isDNI = false, isComission = false, isDay = false, isMonth = false, isYear = false;
    string newName;
    long long int newDNI;
    Seller *previous = NULL;
    Seller *current = findSeller(list, dni, previous);

    if (current != NULL){

        do {
            system("cls");
            fflush(stdin);
            cout << BLUE "\t-OPCIONES-" NC<< endl;
            cout << left << setw(1) << "1-" << setw(12) << "Nombre"<< "| " << setw(15) << current->seller.name << (isName ? GREEN "*" NC: "") << endl;
            cout << left << setw(1) << "2-" << setw(12) << "DNI"<< "| " << setw(15) << current->seller.dni << (isDNI ? GREEN "*" NC: "") << endl;
            cout << "-Admision-----+ " << endl;
            cout << left << setw(1) << "3-" << setw(12) << "Dia:"<< "| " << setw(15) << current->admissionDay.day << (isDay ? GREEN "*" NC: "") << endl;
            cout << left << setw(1) << "4-" << setw(12) << "Mes:"<< "| " << setw(15) << current->admissionDay.month << (isMonth ? GREEN "*" NC: "") << endl;
            cout << left << setw(1) << "5-" << setw(12) << "Anio:"<< "| " << setw(15) << current->admissionDay.year << (isYear ? GREEN "*" NC: "") << endl;
            cout << "--------------+" << endl;
            cout << left << setw(1) << "6-" << setw(12) << "Comision"<< "| " << setw(15) << current->commission << (isComission ? GREEN "*" NC: "") << endl;
            cout << "0- Salir" << endl;

            option = validateNumber("Introduce la opcion >> ");
            cin.ignore();


            switch (option){
            case 1:
                cout << endl;
                cout << "+\tEditar nombre" << endl;
                cout << "| Nuevo nombre: ";
                getline(cin, newName);
                current->seller.name = newName;
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
                current->seller.dni =  newDNI;
                cout << "|" <<endl;
                cout << "+ "<<GREEN "DNI editado con exito!" NC;
                isDNI = true;
                fileUploadFunc(list);
                _getch();
                break;

            case 3:
                cout << endl;
                cout << "+\tEditar dia" << endl;
                current->admissionDay.day = validateNumber("| Nuevo dia >> ");
                cout << "|" <<endl;
                cout << "+ "<<GREEN "Dia editado con exito!" NC;
                isDay = true;
                fileUploadFunc(list);
                _getch();
                break;

            case 4:
                cout << endl;
                cout << "+\tEditar mes" << endl;
                current->admissionDay.month = validateNumber("| Nuevo mes >> ");;
                cout << "|" <<endl;
                cout << "+ "<<GREEN "Mes editado con exito!" NC;
                isMonth = true;
                fileUploadFunc(list);
                _getch();
                break;
            case 5:
                cout << endl;
                cout << "+\tEditar anio" << endl;
                current->admissionDay.year = validateNumber("| Nuevo anio >> ");;
                cout << "|" <<endl;
                cout << "+ "<<GREEN "Mes editado con exito!" NC;
                isYear = true;
                fileUploadFunc(list);
                _getch();
                break;

            case 6:
                cout << endl;
                cout << "+\tEditar comision" << endl;
                current->commission = validateNumber("| Nueva comision >> ");;
                cout << "|" <<endl;
                cout << "+ "<<GREEN "Mes editado con exito!" NC;
                isComission = true;
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
        } while (option != 0);
    } else {
        cout << REDB " Articulo no existe!" NC << endl;
        _getch();
    }
}

void viewSeller(Seller *);
void searchSeller(Seller* list){
    Seller* listComplete = list;
    Seller* current = list;
    int option, count, day, month, year;
    string name;
    long long int dni;
    do {
        system("cls");
        count = 0;
        cout << BLUE "\t-BUSCAR VENDEDOR-" NC<< endl;
        cout << "1- Nombre" << endl;
        cout << "2- DNI" << endl;
        cout << "3- Fecha admision" << endl;
        cout << "0- salir" << endl;
        cout << "Introduce la opcion >> ";

        option = validateNumber("Introduce la opcion >> ");
        cin.ignore();

        switch (option){
        case 1:
            system("cls");
            cout << BLUE "\t BUSQUEDA POR NOMBRE" NC<< endl;
            cout << "Introduce el nombre >> ";
            getline(cin, name);
            while(current != NULL) {
                if(current->seller.name == name ) {
                    viewSeller(current);
                    count++;
                }
                current = current->next;
            }
            cout << endl <<(count == 0? RED : GREEN) << "Busqueda terminada " << "[" << count <<"]" NC<< endl;
            _getch();
            break;

        case 2:
            system("cls");
            cout << BLUE "\t BUSQUEDA POR DNI" NC<< endl;
            dni = validateNumber("Introduce el DNI >> ");
            while(current != NULL) {
                if(current->seller.dni == dni ) {
                    viewSeller(current);
                    count++;
                }
                current = current->next;
            }
            cout << endl <<(count == 0? RED : GREEN) << "Busqueda terminada " << "[" << count <<"]" NC<< endl;
            _getch();
            break;

        case 3:
            system("cls");
            cout << BLUE "\t BUSQUEDA POR FECHA DE ADMISION" NC<< endl;
            day = validateNumber("Introduce el dia >> ");
            month = validateNumber("Introduce le mes >> ");
            year = validateNumber("Introduce el anio >> ");
            while(current != NULL) {
                if((current->admissionDay.day == day) && (current->admissionDay.month == month) && (current->admissionDay.year == year) ) {
                    viewSeller(current);
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
    } while (option != 0);
}

void viewSeller(Seller *seller){
    cout << endl << "CLIENTE: " << seller->seller.name <<endl;
    cout << "DNI:  " << seller->seller.dni<< endl;
    cout << "FECHA DE ADMISION: " <<to_string(seller->admissionDay.day)  + "/" + to_string(seller->admissionDay.month) + "/" + to_string(seller->admissionDay.year)  << endl;
    cout << "COMISION: " << seller->commission << endl;
}



void removeSeller(Seller *&list, long long int dni){
    string option;
    Seller *previous = NULL;
    Seller *current = findSeller(list, dni, previous);

    if (current != NULL){
        fflush(stdin);
        cout << "Vendedor: " << current->seller.name << endl;
        cout << "Desea eliminar el vendedor (s/n) >> ";
        getline(cin, option);
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