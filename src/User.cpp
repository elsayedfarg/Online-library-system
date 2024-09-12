#include "User.h"
int User::count=0;

//------------------------------------------------ Constructors ---------------------------------------------------//
User::User():name(""),age(0),id(++count),password(""),email("") {}

User::User(string name, int age, string password, string email)
{
//    The this pointer is used to refer to the current instance of the class.
//    This is necessary when the parameter name and the data member name are the same, to differentiate between the two.
    this->name = name;
    this->age = age;
    this->password = password;
    this->email = email;
//    Why Increment in Both Constructors?
//    You increment count in both constructors to ensure that the id assigned to each User object is unique and sequential,
//    regardless of how the User object is created. This guarantees that every User object, whether created with default or parameterized values, has a unique identifier.
//    In C++, it's not possible for the same object to be constructed using both constructors because each object can only be created once.
//    Constructors are called when an object is instantiated, and each instantiation uses only one constructor.
    count++;
    id=count;
}

// Copy Constructor (when a new object needs to get the same values from an existing object)
// Using const ensures that the source object, from which values are being copied, cannot be changed.
User::User(const User &u)
{
    name=u.name;
    age=u.age;
    password=u.password;
    email=u.email;
//    Typically, count is used to assign a unique identifier to each new object.
//    Since the copy constructor creates a new object that is a copy of an existing object, the id of the new object should be the same as that of the object being copied.
    id=u.id;
}
//------------------------------------------------// Constructors //---------------------------------------------------//

//------------------------------------------------ Setters ---------------------------------------------------//
void User::setName(string n)
{
    name=n;
}
void User::setPassword(string p)
{
    password=p;
}
void User::setEmail(string e)
{
    email=e;
}
void User::setAge(int a)
{
    age=a;
}
void User::setId(int i)
{
    id=i;
}
//------------------------------------------------// Setters //---------------------------------------------------//

//------------------------------------------------ Getters ---------------------------------------------------//
string User::getName() const
{
    return name;
}
string User::getPassword() const
{
    return password;
}
string User::getEmail() const
{
    return email;
}
int User::getAge() const
{
    return age;
}
int User::getId() const
{
    return id;
}
//------------------------------------------------// Getters //---------------------------------------------------//

//------------------------------------------------ Overloading (==) Operator ---------------------------------------------------//
bool User::operator==(const User &u)
{
//    This function will work only with the copy constructor because the ID values are the same. (User u1; User u2=u1;)
    return (name==u.name && age==u.age && id==u.id && password==u.password && email==u.email);
}

//void User::operator=(const User &u)
//{
//    name=u.name;
//    age=u.age;
//    password=u.password;
//    email=u.email;
//}
//------------------------------------------------// Overloading (==) Operator //---------------------------------------------------//

//------------------------------------------------ Overloading stream operators ---------------------------------------------------//
istream& operator>>(istream &input, User &u)
{
    cout<<"\t\t\t\t\t\t Enter the user information \n";
    cout<<"Enter the name: ";
    input>>u.name;
    cout<<"Enter the age: ";
    input>>u.age;
    cout<<"Enter the password: ";
    input>>u.password;
    cout<<"Enter the email: ";
    input>>u.email;
    cout<<"\n";
    return input;
}

ostream& operator<<(ostream &output,const User &u)
{
    output<<"\n========== User["<<u.id<<"]"<<" Info =========="<<'\n';
    output<<"Name: "<<u.name;
    output<<" | Age: "<<u.age;
    output<<" | Id: "<<u.id;
    output<<" | Email: "<<u.email;
    cout<<"\n================================================================================================="<<'\n'<<'\n';
    return output;
}
//------------------------------------------------// Overloading stream operators //---------------------------------------------------//
