#ifndef USER_H
#define USER_H
#include <string>
#include<iostream>
using namespace std;

class User
{
private:
    string name;
    int age;
    int id;
    string password;
    string email;

public:
    // Every created object has its own member variables, but static members are shared among all objects.
    // The count variable will be incremented by the constructor each time a new user is created, ensuring that the id value is unique.
    // The count variable is defined as public because it can be accessed without creating an object, whereas if it were private, it could not be accessed directly.
    static int count;
    User();
    User(string, int, string, string );
    //    The copy constructor is a special type of constructor that initializes a new object as a copy of an existing object.(using call by reference here)
    User(const User &);

    // Setters
    void setName(string );
    void setPassword(string );
    void setEmail(string );
    void setAge(int );
    void setId(int );

    // Getters
    //    The const keyword indicates that this member function (getName()) does not modify any member variables of the class
    string getName() const;
    string getPassword() const;
    string getEmail() const;
    int getAge() const;
    int getId() const;

    // Operator overloading (using call by reference here)
    bool operator==(const User &);

//    User u1;
//    User u2=u1;//this line call the copy constructor
//    User u3;
//    User u4;
//    u3=u4;//this line will not call the copy constructor so you must overload it to create a new object but with new id
//    void operator=(const User &);

    // Friend functions for stream operators (operator overloading)
    //  friend keyword: This allows these functions to access the private and protected members of the class while still being defined outside the class.
    //  (const) used for the output because cout will not change anything, unlike the input (cin).
    friend ostream& operator<<(ostream &, const User &);
    friend istream& operator>>(istream &, User &);
};
#endif // USER_H
