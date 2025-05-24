#ifndef BOOK
#define BOOK
#include<iostream>
using namespace std;
class Book
{
    string title, author, ISBN;
    public:
    Book(){}
    Book(string title,string author,string ISBN){
        this->author = author;
        this->title = title;
        this->ISBN = ISBN;
    }
    string getTitle(){return title;}
    string getAuthor(){return author;}
    string getISBN(){return ISBN;}

};


#endif