// #include <iostream>
// #include<string>
// #include<conio.h>
#include<fstream>
#include <iomanip>
#include <sstream>
using namespace std;

const string DBArticles = "db/Articles.txt" ;
const string DBClients = "db/Clients.txt" ;
const string DBSellers = "db/Sellers.txt" ;



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
        } else {
            file<<title<<endl;
            file.close();

        }
    }

}

// READ FILE ARTICLE ----------------------------------------
void readFileArticle(Article *&list, long int &currentKey){

    ifstream file;
    
    string text, code, name;
    long int key = 0, stock;
    int count = 0;
    float price;
    list = NULL;

    file.open(DBArticles.c_str(), ios:: in);

    if (file.fail()){
        cout << "No se puede abrir el archivo";
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
                key++;
                addNode(list, createArticle(key, code, name, price, stock), true, fileUploadArticle);
            }
            count++;

        } 
    }
    currentKey = key;
    file.close();
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

// FILE UPLOAD CLIENT ----------------
void fileUploadCLient(Client *&list){
    ofstream file;
    file.open(DBClients.c_str(), ios::out);  // Abre el archivo en modo de escritura, esto borrará el contenido existente y carga toda la lista de nuevo

    if (file.fail()){
        cout << "No se puede abrir el archivo";
        return;
    }
    Client* current = list;
    file << "CLIENTES" << endl;
    while(current != NULL){
        file << current->client.dni << "-";
        file << current->client.name << "-";
        file << current->address << "-";
        file << current->number << endl;
        current = current->next;
    }

    file.close();
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
    file << "CLIENTES" << endl;
    while(current != NULL){
        file << current->seller.dni << "-";
        file << current->seller.name << "-";
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
        if(text != "CLIENTES"){
            stringstream ss(text);
            while(getline(ss, text, '-')) {
                if (count == 0){
                    dni = stoll(text);
                    countSeller++;
                } else if (count == 1) {
                    name = text;
                } else if (count == 2) {
                    stringstream ss(text);
                    while(getline(ss, text, '/')){
                        if (count == 2){
                            day=stoi(text);

                        } else if (count == 3) {
                            month=stoi(text);

                        } else if (count == 4){
                            year=stoi(text);
                            break;
                        }
                        count++;

                    }
                } else if (count == 4){
                    number = text;
                    count = -1;
                    addNode(list, createSeller(dni, name, day, month, year, stoll(number)), true, fileUploadSeller);
                }
                count++;
            }
        }
    }
    file.close();
}