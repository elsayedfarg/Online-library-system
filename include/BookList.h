#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "Book.h"
#include <string>
#include<iostream>
using namespace std;

class BookList
{
private:
    Book* books;
    int capacity;
    int booksCount;
public:
    BookList();
    BookList(int);
    BookList(const BookList&);//
    void addBook(Book&);
    Book* searchBook(string);
    Book* searchBook(int);
    void deleteBook(int);
    Book getTheHighestRatedBook();
    void getBooksForUser(User&);
    Book& operator[](int);
    friend ostream& operator<<(ostream&, const BookList&);
    ~BookList();
};
#endif // BOOKLIST_H
