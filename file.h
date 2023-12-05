#include <iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include <iomanip>
using namespace std;

const string DB = "db/Articles.txt" ;

void fileUpload(Article *&);

void createFile(){
    ofstream file;
    ifstream infile(DB.c_str());
    if (infile.good()){
        infile.close();
    } else {

        file.open(DB.c_str(), ios::out);

        if (file.fail()){
            cout << "No se puede abrir el archivo";
        } else {
            file<<"ARTICULOS"<<endl;
            file.close();

        }
    }

}

// void writeFile(long int key, string code, string name, float price, int stock){
//     ofstream file;
//     file.open(DB.c_str(), ios::app);

//     if (file.fail()){
//         cout << "No se puede abrir el archivo";
//     } else {
//         file << code << endl;
//         file << name << endl;
//         file << std::fixed << std::setprecision(2) << price << endl;  // Aquí es donde se escribe el precio con precisión decimal
//         file << stock << endl;
//     }
//     file.close();   
// }



void readFile(Article *&list, long int &currentKey){

    ifstream file;
    
    string text, code, name;
    long int key = 0, stock;
    int count = 0;
    float price;
    list = NULL;

    file.open(DB.c_str(), ios:: in);

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
                addArticle(list, creatArticle(key, code, name, price, stock), true, fileUpload);
            }
            count++;

        } 
    }
    currentKey = key;
    file.close();
}
// file upload
void fileUpload(Article *&list){
    ofstream file;
    file.open(DB.c_str(), ios::out);  // Abre el archivo en modo de escritura, esto borrará el contenido existente y carga toda la lista de nuevo

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

