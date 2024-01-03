using namespace std;

struct Person{
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
    Person person;
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
    Person person;
    AdmissionDay admissionDay;
    int commission;
    Seller *next;
};