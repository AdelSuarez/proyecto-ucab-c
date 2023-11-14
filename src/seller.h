#include<iostream>
#include "person.h"
using namespace std;

struct AdmissionDay {
    int day;
    int month;
    int year;
};

struct Seller {
    Person seller;
    AdmissionDay admissionDay;
    int commission;
};
