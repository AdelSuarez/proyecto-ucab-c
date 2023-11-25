#include<iostream>
#include <cctype>
using namespace std;

string toUpper(string str) {
    if (!str.empty()) {
        str[0] = toupper(str[0]);
    }
    return str;
}

string toLower(string str) {
    if (!str.empty()) {
        str[0] = tolower(str[0]);
    }
    return str;
}