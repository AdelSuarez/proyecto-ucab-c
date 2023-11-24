#include <iostream>
#include<string>
#include<conio.h>
#include<fstream>

using namespace std;

const string DB = "db/Articles.txt" ;

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

void writeFile(string code, string name, int price, int stock){
    ofstream file;
    file.open(DB.c_str(), ios::app);

    if (file.fail()){
        cout << "No se puede abrir el archivo";
    } else {
        file << code << endl;
        file << name << endl;
        file << price << endl;
        file << stock << endl;
    }
    file.close();   
}




void readFile(Article *&list){
    //TODO Corregir el error de que guarda dos veces los datos en la la lista cuando se llama por segunda vez la funcion 

    ifstream file;
    
    string text, code, name;
    long int key = 0, stock;
    int count = 0;
    float price;

    file.open(DB.c_str(), ios:: in);

    if (file.fail()){
        cout << "No se puede abrir el archivo";
    }

    while(!file.eof()){
        getline(file, text);
        if (text!="ARTICULOS"){
            if (count == 0){
                code = text;
                count++;
            } else if (count == 1) {
                name = text;
                count++;
            } else if (count == 2) {
                price = stof(text);
                count++;
            } else if (count == 3){
                stock = stoi(text);
                count = 0;
                key++;
                addArticle(list, creatArticle(key, code, name, price, stock), true);
            }
            
        } 
    }

    file.close();
}

// void readFile(Article *&list){
//     long int key = 0;
//     ifstream file(DB.c_str());

//     if (file.fail()){
//         cout << "No se puede abrir el archivo";
//         return;
//     }

//     if (file.peek() == ifstream::traits_type::eof()){
//         // El archivo está vacío
//         return;
//     }

//     string text, code, name;
//     float price;
//     long int stock;
//     int count = 0;

//     while(getline(file, text)){
//         if (text != "ARTICULOS"){
//             switch (count) {
//                 case 0:
//                     code = text;
//                     break;
//                 case 1:
//                     name = text;
//                     break;
//                 case 2:
//                     price = stof(text);
//                     break;
//                 case 3:
//                     stock = stoi(text);
//                     key++;
//                     addArticle(list, creatArticle(key, code, name, price, stock), true);
//                     count = -1; // Se restablecerá a 0 en la siguiente línea
//                     break;
//             }
//             count++;
//         }
//     }

//     file.close();
// }