#include <iostream>
#include<string>
#include<conio.h>
using namespace std;

struct Article {
    string code;
    string name;
    float price;
    int stock;
    Article *next;
};



void addArticle(Article *list, string code, string name, float price, int stock){
    Article *new_article = new Article();
    new_article->code = code;
    new_article->name = name;
    new_article->price = price;

}