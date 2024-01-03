using namespace std;
#include <iostream>


Seller* createSeller(long long int dni, string name, int day, int month, int year, int comission){
    Seller *seller = new Seller();
    seller->person.dni = dni;
    seller->person.name = name;
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
        cout << left << setw(15) << current->person.dni << setw(29) << current->person.name << (current->admissionDay.day < 10? "0": "")  << current->admissionDay.day << "/" << (current->admissionDay.month < 10? "0": "") << current->admissionDay.month<< "/" << setw(27)<< current->admissionDay.year << setw(5) << current->commission << "%" << endl;
        current = current->next;
    }
    cout << endl;
    cout << "Presione cualquier tecla para continuar";
    _getch();
}



void editSeller(Seller *&list, long long int dni, void (*fileUploadFunc)(Seller *&)){
    int option;
    bool isName = false, isDNI = false, isComission = false, isDay = false, isMonth = false, isYear = false;
    long long int newDNI;
    int newDay, newMonth, newYear;
    Seller *previous = NULL;
    Seller *current = find(list, dni, previous);

    if (current != NULL){

        do {
            system("cls");
            fflush(stdin);
            cout << BLUE "\t-OPCIONES-" NC<< endl;
            cout << left << setw(1) << "1-" << setw(12) << "Nombre"<< "| " << setw(15) << current->person.name << (isName ? GREEN "*" NC: "") << endl;
            cout << left << setw(1) << "2-" << setw(12) << "DNI"<< "| " << setw(15) << current->person.dni << (isDNI ? GREEN "*" NC: "") << endl;
            cout << "-Admision-----+ " << endl;
            cout << left << setw(1) << "3-" << setw(12) << "Dia:"<< "| " << setw(15) << current->admissionDay.day << (isDay ? GREEN "*" NC: "") << endl;
            cout << left << setw(1) << "4-" << setw(12) << "Mes:"<< "| " << setw(15) << current->admissionDay.month << (isMonth ? GREEN "*" NC: "") << endl;
            cout << left << setw(1) << "5-" << setw(12) << "Anio:"<< "| " << setw(15) << current->admissionDay.year << (isYear ? GREEN "*" NC: "") << endl;
            cout << "--------------+" << endl;
            cout << left << setw(1) << "6-" << setw(12) << "Comision"<< "| " << setw(15) << current->commission << (isComission ? GREEN "*" NC: "") << endl;
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
                current->person.dni =  newDNI;
                cout << "|" <<endl;
                cout << "+ "<<GREEN "DNI editado con exito!" NC;
                isDNI = true;
                fileUploadFunc(list);
                _getch();
                break;

            case 3:
                cout << endl;
                cout << "+\tEditar dia" << endl;
                do {
                    newDay = validateNumber("| Nuevo dia >> ");
                    validateDate(newDay, limiteDay);
                }while (newDay > limiteDay || newDay == 0);

                current->admissionDay.day = newDay;
                cout << "|" <<endl;
                cout << "+ "<<GREEN "Dia editado con exito!" NC;
                isDay = true;
                fileUploadFunc(list);
                _getch();
                break;

            case 4:
                cout << endl;
                cout << "+\tEditar mes" << endl;
                do {
                    newMonth = validateNumber("| Nuevo mes >> ");
                    validateDate(newMonth, limiteMonth);
                } while( newMonth > limiteMonth || newMonth == 0);

                current->admissionDay.month = newMonth;
                cout << "|" <<endl;
                cout << "+ "<<GREEN "Mes editado con exito!" NC;
                isMonth = true;
                fileUploadFunc(list);
                _getch();
                break;
            case 5:
                cout << endl;
                cout << "+\tEditar año" << endl;
                do {
                    newYear = validateNumber("| Nuevo año >> ");
                    validateYear(newYear, limiteYear);
                } while (newYear < limiteYear || newYear == 0);

                current->admissionDay.year = newYear;
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


void viewSeller(Seller *seller){
    cout << endl << left << setw(20) << "CLIENTE: " << seller->person.name <<endl;
    cout << left << setw(20) << "DNI:  " << seller->person.dni<< endl;
    cout << left << setw(20) << "FECHA DE ADMISION: " <<to_string(seller->admissionDay.day)  + "/" + to_string(seller->admissionDay.month) + "/" + to_string(seller->admissionDay.year)  << endl;
    cout << left << setw(20) << "COMISION: " << seller->commission << endl;
}

void searchSeller(Seller *list, string criterion, string value){
    Seller* current = list;
    int count = 0;
    while(current != NULL) {
        if((criterion == "name" && current->person.name == value) ||
           (criterion == "dni" && to_string(current->person.dni) == value) ||
           (criterion == "admissionDay" && current->admissionDay.day == stoi(value.substr(0, 2)) && 
                                         current->admissionDay.month == stoi(value.substr(3, 2)) && 
                                         current->admissionDay.year == stoi(value.substr(6, 4)))) {
            viewSeller(current);
            count++;
        }
        current = current->next;
    }
    cout << endl <<(count == 0? RED : GREEN) << "Busqueda terminada " << "[" << count <<"]" NC<< endl;
    _getch();
}


void searchMenu(Seller* list){
    int option;
    string text;
    do {
        system("cls");
        cout << BLUE "\t-BUSCAR VENDEDOR-" NC<< endl;
        cout << "1- Nombre" << endl;
        cout << "2- DNI" << endl;
        cout << "3- Fecha de admision" << endl;
        cout << "0- salir" << endl;

        option = validateNumber("Introduce la opcion >> ");

        switch (option){
            case 1:
                system("cls");
                cout << BLUE "\t BUSQUEDA POR NOMBRE" NC<< endl;
                text = isVoid("Introduce el nombre >> ");
                searchSeller(list, "name", text);
                break;
            case 2:
                system("cls");
                cout << BLUE "\t BUSQUEDA POR DNI" NC<< endl;
                text = isVoid("Introduce el DNI >> ");
                searchSeller(list, "dni", text);
                break;
            case 3:
                system("cls");
                cout << BLUE "\t BUSQUEDA POR FECHA DE ADMISION" NC<< endl;
                text = isVoid("Introduce la fecha de admision (dd/mm/aaaa) >> ");
                searchSeller(list, "admissionDay", text);
                break;
            case 0:
                break;
            default:
                cout << " " << REDB "La opcion no existe" NC;
                _getch();
                break;
        } 
    } while(option != 0);
}

void removeSeller(Seller *&list, long long int dni){
    string option;
    Seller *previous = NULL;
    Seller *current = find(list, dni, previous);

    if (current != NULL){
        fflush(stdin);
        cout << "Vendedor: " << current->person.name << endl;
        option = isVoid("Desea eliminar el vendedor (s/n) >> ");
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