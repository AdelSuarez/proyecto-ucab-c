
SalesCheck* createBill(int key, Seller* seller, Client* client, Article* list, int discount, long int totalAmount, long int discountedAmount){
    SalesCheck *bill = new SalesCheck();
    bill->key = key;
    bill->seller = *seller;
    bill->client = *client;
    bill->listArticles = list;

    bill->discount = discount;
    bill->totalAmount = totalAmount;
    bill->discountedAmount = discountedAmount;
    
    return bill;
}

void showCheck(SalesCheck *list) {
    system("cls");

    SalesCheck *current = new SalesCheck();
    current = list;

    cout <<BLUE "\t\t\t\t-FACTURAS-" NC<< endl;
    cout << BLACK BLUEB ;
    cout << left << setw(15) << "ID" << setw(30) << "NOMBRE" << setw(30) << "DNI" << setw(12) << "MONTO" << endl;
    cout << NC;
    while(current != NULL){
        cout << left << setw(15) << current->key << setw(30) << current->client.person.name << setw(30) << current->client.person.dni << setw(12) << current->discountedAmount << endl;
        current = current->next;
    }
    cout << endl;
    cout << "Presione cualquier tecla para continuar";
    _getch();
}

void removeCheck(SalesCheck *&list, int long key){
    string opt;
    SalesCheck *previous = NULL;
    SalesCheck *current = findKey(list, key, previous);

    if(current != NULL){
        fflush(stdin);
        cout << "FACTURA: " << current->key << endl;
        cout << "CLIENTE: " << current->client.person.name << endl;
        cout << "DNI: " << current->client.person.dni << endl;

        opt = isVoid("Desea eliminar el articulo (s/n) >> ");
        if ((opt == "s") || (opt == "S")){
            removeNode(list,current, previous);
        } else {
            return;
        }

    } else {
        cout << REDB "La factura no existe!" NC;
        _getch();
    }

}



void editChek(SalesCheck *&list, Seller *&listSeller, Client *&listClient, int long key ){
    bool isSeller = false, isClient = false, isPrice = false, isStock = false;
    int option;
    long long dni;
    long int newStock;
    Seller *previousSeller = NULL;
    Client *previousClient = NULL;


    SalesCheck *previous = NULL;
    SalesCheck *current = findKey(list, key, previous);

    do {
        system("cls");
        fflush(stdin);
        cout << BLUE "\t-OPCIONES-" NC<< endl;
        cout << left << setw(1)<<"Clave "<< setw(5) << current->key  <<"| ARTICULO"<< endl;
        cout << left << setw(1) << "1-" << setw(9) << "Vendedor"<< "| " << setw(12) << current->seller.person.name << (isSeller ? GREEN "*" NC: "") << endl;
        cout << left << setw(1) << "2-" << setw(9) << "Cliente"<< "| " << setw(12) << current->client.person.name << (isClient ? GREEN "*" NC: "") << endl;
        // cout << left << setw(1) << "3-" << setw(9) << "Precio"<< "| " << setw(12) << current->price << (isPrice ? GREEN "*" NC: "") << endl;
        // cout << left << setw(1) << "4-" << setw(9) << "Stock"<< "| " << setw(12) << current->stock << (isStock ? GREEN "*" NC: "") << endl;
        cout << "0- Salir" << endl;

        option = validateNumber("Introduce la opcion >> ");

        switch (option){
            case 1:
                cout << endl;
                while (true){
                    cout << "+\tEditar Vendedor" << endl;

                    dni = validateNumber("| DNI >> ");
                    Seller *currentSeller = find(listSeller, dni, previousSeller);

                    if (currentSeller != NULL) {
                        current->seller.person.name = currentSeller->person.name;
                        current->seller.person.dni = currentSeller->person.dni;
                        current->seller.admissionDay.day = currentSeller->admissionDay.day;
                        current->seller.admissionDay.month = currentSeller->admissionDay.month;
                        current->seller.admissionDay.year = currentSeller->admissionDay.year;
                        current->seller.commission = currentSeller->commission;
                        cout << "|" <<endl;
                        cout << "+ "<<GREEN "Vendedor editado con exito!" NC;
                        isSeller = true;

                        break;
                    } else {
                        cout << REDB "No existe el vendedor" NC;
                        _getch();

                    }

                }

                _getch();
                break;

            case 2:
                cout << endl;
                while (true){
                    cout << "+\tEditar cliente" << endl;

                    dni = validateNumber("| DNI >> ");
                    Client *currentClient = find(listClient, dni, 
        previousClient);

                    if (currentClient != NULL) {
                        current->client.person.name = currentClient->person.name;
                        current->client.person.dni = currentClient->person.dni;
                        current->client.number = current->client.number;
                        current->client.address = current->client.address;
                        cout << "|" <<endl;
                        cout << "+ "<<GREEN "Cliente editado con exito!" NC;
                        isClient = true;

                        break;
                    } else {
                        cout << REDB "No existe el cliente" NC;
                        _getch();

                    }

                }

                _getch();
                break;

            // case 3:
            //     cout << endl;
            //     cout << "+\tEditar price" << endl;
            //     current->price = validateNumber("| Nuevo precio >> ");
            //     cout << "|" <<endl;
            //     cout << "+ "<<GREEN "Precio editado con exito!" NC;
            //     isPrice = true;
            //     _getch();
            //     break;

            // case 4:
            //     cout << endl;
            //     cout << "+\tEditar stock" << endl;
            //     do {
            //         newStock = validateNumber("| Nuevo stock >> ");
            //     } while (newStock < 1);
            //     current->stock = newStock;
            //     cout << "|" <<endl;
            //     cout << "+ "<<GREEN "Stock editado con exito!" NC;
            //     isStock = true;
            //     _getch();
            //     break;

            case 0:
                break;
            default:
                cout << REDB "La opcion no existe" NC;
                _getch();
                break;
        }
    } while(option !=0);
}

