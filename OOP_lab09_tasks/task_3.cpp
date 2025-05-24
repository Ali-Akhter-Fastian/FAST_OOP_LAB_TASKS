//TASK # 03 BY ALI AKHTER 24k-0809
#include <iostream>
#include "Book.h"
using namespace std;
class Library
{
    Book *books = NULL;
    int booksCount;
public:
    Library(){this->booksCount=0;}
    ~Library()
    {
        delete[] books;
    }

    void addBook(Book *book)
    {

        Book *temp = new Book[booksCount + 1];

        for (int i = 0; i < booksCount; i++)
            temp[i] = books[i];
        temp[booksCount] = *book;
        delete[] books;
        books = temp;
        booksCount++;

    }
    void removeBook(Book *book)
    {

        int indexRem,i;
        for (i = 0; i < booksCount; i++)
        {
            if (book->getISBN() == books[i].getISBN())
            {
                indexRem = i;
                break;
            }
        }
        if (i == booksCount)
        {
            cout << "Book does not found!!!" << endl;
            return;
        }

        Book *temp = new Book[booksCount - 1];
        int tempIndex = 0;
        for (int i = 0; i < booksCount; i++)
        {
            if (i != indexRem)
            {
                temp[tempIndex++] = books[i];
            }
        }
        delete[] books;
        books = temp;
        booksCount--;
        cout << "Removed Book: " << book->getTitle() << " (ISBN: " << book->getISBN() << ")" << endl;
    
    }
    void searchBook(Book *book)
    {
        int i;
        for (i = 0; i < booksCount; i++)
        {
            if (book->getISBN() == books[i].getISBN())
            {
                cout << "Book found at index " << i << endl;
                break;
            }
        }
        if (i == booksCount)
        {
            cout<<"Book does not found"<<endl;
            return;
        }
    }
    void displayAllBooks()
    {
        cout << endl<<"Current Library Books" << endl;
        if (booksCount == 0)
        {
            cout << "Library is empty." << endl;
            return;
        }
        for (int i = 0; i < booksCount; i++)
        {
            cout << i + 1 << ". " << books[i].getTitle()
                 << " by " << books[i].getAuthor()
                 << " (ISBN: " << books[i].getISBN() << ")" << endl;
        }
        cout<<endl;
    }
};

int main(){
    Book *b = new Book[5];
    b[0] = Book("Al Jihad fil Islam", "Syed Moudoudi", "1950");
    b[1] = Book("1947", "Causes of Indian revolt", "2001");
    b[2] = Book("The Great Gatsby", "F. Scott Fitzgerald", "1925");
    b[3] = Book("Khilafat e Mulokiat", "Syed Moudoudi ", "1981");
    b[4] = Book("To Kill a Mockingbird", "Harper Lee", "1960");

    Library li;

    cout << endl<<"Adding Books"<<endl;
    li.addBook(&b[0]);
    li.addBook(&b[1]);
    li.addBook(&b[2]);
    li.addBook(&b[3]);
    li.addBook(&b[4]);

    cout << endl<<"Removing a Book"<<endl;
    li.removeBook(&b[2]);

    cout << endl<<"Searching a Book"<<endl;
    li.searchBook(&b[3]);

    li.displayAllBooks();
    return 0;
}
