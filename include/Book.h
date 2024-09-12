#ifndef BOOK_H
#define BOOK_H
#include "User.h"
#include <string>
#include<iostream>
using namespace std;

class Book
{
private:
    int numOfRates;
    double sumOfRates;
    string title;
    string isbn;
    int id;
    string category;
    double averageRating;
//    aggregation
    User author;// normally created object
//    User *author;// object created via pointer || We will use a pointer to prevent creating a user with every book created.
public:
    // Every created object has its own member variables, but static members are shared among all objects.
    // The count variable will be incremented by the constructor each time a new book is created, ensuring that the id value is unique.
    // The count variable is defined as public because it can be accessed without creating an object, whereas if it were private, it could not be accessed directly.
    static int count;

    Book();
//    ~Book();
    Book(string, string, string);
    //    The copy constructor is a special type of constructor that initializes a new object as a copy of an existing object.(using call by reference here)
    Book(const Book&);

    // Setters
    void setTitle(string);
    void setISBN(string);
    void setId(int);
    void setCategory(string);
    void setAuthor(const User&);

    // Getters
    string getTitle() const;
    string getISBN() const;
    int getId() const;
    string getCategory() const;
    User getAuthor() const;
    double getAverageRating()const;

    bool operator==(const Book&);

    friend ostream& operator<<(ostream&, const Book&);
    friend istream& operator>>(istream&, Book&);

    void rateBook(double);
};

#endif // BOOK_H
