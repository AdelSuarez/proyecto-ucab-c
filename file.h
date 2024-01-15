#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

const string DBArticles = "db/Articles.txt" ;
const string DBClients = "db/Clients.txt" ;
const string DBSellers = "db/Sellers.txt" ;
const string DBSelesCheck = "db/check.txt" ;

void fileUploadArticle(Article *&);

void createFile(string title, string db){
    ofstream file;
    ifstream infile(db.c_str());
    if (infile.good()){
        infile.close();
    } else {

        file.open(db.c_str(), ios::out);

        if (file.fail()){
            cout << "No se puede abrir el archivo";
            _getch();
        } else {
            file<<title<<endl;
            file.close();

        }
    }

}

// READ FILE ARTICLE ----------------------------------------
void readFileArticle(Article *&list, long int &currentKey, string db, bool upload){

    ifstream file;
    
    string text, code, name;
    long int stock;
    int count = 0;
    float price;
    // list = NULL;

    file.open(db.c_str(), ios:: in);

    if (file.fail()){
        cout << REDB "No se puede abrir el archivo" NC;
        _getch();
        return;
    }

    while(!file.eof()){
        getline(file, text);
        if (text!="ARTICULOS"){
            if (count == 0){
                code = text;
            } else if (count == 1) {
                name = text;
            } else if (count == 2) {
                price = stof(text);
            } else if (count == 3){
                stock = stoi(text);
                count = -1;
                currentKey++;
                addNode(list, createArticle(currentKey, code, name, price, stock), true);
                fileUploadArticle(list);
            }
            count++;

        } 
    }
    file.close();
    if (upload){
        cout << BLACK GREENB  "Archivo cargado con exito." NC;
        _getch();
    }
}


// FILE UPLOAD ARTICLE -----------------
void fileUploadArticle(Article *&list){
    ofstream file;
    file.open(DBArticles.c_str(), ios::out);  // Abre el archivo en modo de escritura, esto borrará el contenido existente y carga toda la lista de nuevo

    if (file.fail()){
        cout << "No se puede abrir el archivo";
        return;
    }
    Article* current = list;
    file << "ARTICULOS" << endl;
    while(current != NULL){
        file << current->code << endl;
        file << current->name << endl;
        file << std::fixed << std::setprecision(2) << current->price << endl;
        file << current->stock << endl;
        current = current->next;
    }

    file.close();
}


void fileUploadCheck(SalesCheck *&list){
    ofstream file;
    file.open(DBSelesCheck.c_str(), ios::out);  // Abre el archivo en modo de escritura

    if (file.fail()){
        cout << "No se puede abrir el archivo";
        return;
    }
    SalesCheck* current = list;
    file << "FACTURA" << endl;
    while(current != NULL){
        file << current->seller.person.dni << "-" << current->seller.person.name << "-" << current->seller.admissionDay.day << "/"<< current->seller.admissionDay.month << "/"<< current->seller.admissionDay.year << "-"<<current->seller.commission <<endl;
        file << current->client.person.dni << "-" << current->client.person.name << "-" << current->client.address << "-" << current->client.number << endl;
        
        Article* currentArticle = current->listArticles;
        while(currentArticle != NULL){
            file << currentArticle->code << endl;
            file << currentArticle->name << endl;
            file << std::fixed << std::setprecision(2) << currentArticle->price << endl;
            file << currentArticle->stock << endl;
            currentArticle = currentArticle->next;
        }
        file << "--" << endl;
        file << current->discount << endl;
        file << current->totalAmount << endl;
        file << current->discountedAmount << endl;
        current = current->next;   
    }

    file.close();
}


// FILE UPLOAD CLIENT ----------------
void fileUploadCLient(Client *&list){
    ofstream file;
    file.open(DBClients.c_str(), ios::out);  // Abre el archivo en modo de escritura, esto borrará el contenido existente y carga toda la lista de nuevo

    if (file.fail()){
        cout << REDB "No se puede abrir el archivo" NC;
        _getch();
        return;
    }
    Client* current = list;
    file << "CLIENTES" << endl;
    while(current != NULL){
        file << current->person.dni << "-";
        file << current->person.name << "-";
        file << current->address << "-";
        file << current->number << endl;
        current = current->next;
    }

    file.close();
}

void readFileCheck(SalesCheck *&list){
    ifstream file;
    string text;
    list = NULL;

    file.open(DBSelesCheck.c_str(), ios:: in);
    if (file.fail()){
        cout << "No se puede abrir el archivo";
        return;
    }

    while (!file.eof()){
        getline(file, text);
        if(text != "FACTURA"){
            // COntinuar
        }

    }
    
}

// READ FILE CLIENT --------------------------------------
void readFileClient(Client *&list, long int &countClient){
    ifstream file;
    string text, name, address, number;
    long long int dni = 0;
    int count = 0;
    list = NULL;

    file.open(DBClients.c_str(), ios:: in);

    if (file.fail()){
        cout << "No se puede abrir el archivo";
        return;
    }

    while(!file.eof()){
        getline(file, text);
        if(text != "CLIENTES"){
            stringstream ss(text);
            while(getline(ss, text, '-')) {
                if (count == 0){
                    dni = stoll(text);
                    countClient++;
                } else if (count == 1) {
                    name = text;
                } else if (count == 2) {
                    address = text;
                } else if (count == 3){
                    number = text;
                    count = -1;
                    addClient(list, createClient(dni, name, address, stoll(number)), true, fileUploadCLient);
                }
                count++;
            }
        }
    }
    file.close();
}


void fileUploadSeller(Seller *&list){
    ofstream file;
    file.open(DBSellers.c_str(), ios::out);  // Abre el archivo en modo de escritura, esto borrará el contenido existente y carga toda la lista de nuevo

    if (file.fail()){
        cout << "No se puede abrir el archivo";
        return;
    }
    Seller* current = list;
    file << "VENDEDORES" << endl;
    while(current != NULL){
        file << current->person.dni << "-";
        file << current->person.name << "-";
        file << current->admissionDay.day << "/";
        file << current->admissionDay.month << "/";
        file << current->admissionDay.year << "-";
        file << current->commission << endl;
        current = current->next;
    }

    file.close();
}

void readFileSeller(Seller *&list, long int &countSeller){
    ifstream file;
    string text, name, number;
    long long int dni = 0;
    int count = 0, day, month, year;
    list = NULL;

    file.open(DBSellers.c_str(), ios:: in);

    if (file.fail()){
        cout << "No se puede abrir el archivo";
        return;
    }

    while(!file.eof()){
        getline(file, text);
        if(text != "VENDEDORES"){
            stringstream ss(text);
            while(getline(ss, text, '-')) {
                if (count == 0){
                    dni = stoll(text);
                    countSeller++;
                } else if (count == 1) {
                    name = text;
                } else if (count == 2) {
                    stringstream ss(text);
                    string datePart;
                    int dateCount = 0;
                    while(getline(ss, datePart, '/')){
                        if (dateCount == 0){
                            day = stoi(datePart);
                        } else if (dateCount == 1) {
                            month = stoi(datePart);
                        } else if (dateCount == 2){
                            year = stoi(datePart);
                            break;
                        }
                        dateCount++;
                    }
                } else if (count == 3){
                    number = text;
                    count = -1;
                    addNode(list, createSeller(dni, name, day, month, year, stoll(number)), true);
                    fileUploadSeller(list);
                }
                count++;
            }
        }
    }
    file.close();
}
