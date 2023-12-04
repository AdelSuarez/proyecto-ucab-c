#include<string>
using namespace std;


struct Person{
    // TODO Hacer que el dni sea unico en la lista
    long long int dni;
    string name;
};

struct Article {
    long int key;
    string code;
    string name;
    float price;
    long int stock;
    Article *next;
};

struct Client {
    Person client;
    string address;
    long long int number;
    Client *next;
};


struct AdmissionDay {
    int day;
    int month;
    int year;
};

struct Seller {
    Person seller;
    AdmissionDay admissionDay;
    int commission;
    Seller *next;
};