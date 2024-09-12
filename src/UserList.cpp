#include "UserList.h"

//------------------------------------------------ Constructors & Destructor ---------------------------------------------------//
UserList::UserList():capacity(0),usersCount(0) {}
UserList::UserList(int capacity)
{
    this->capacity=capacity;
    //This line will call the default constructor of the User class with the specified capacity.
    users=new User[capacity];
}
UserList::~UserList()
{
    delete[] users;
}
//------------------------------------------------// Constructors & Destructor //---------------------------------------------------//

//------------------------------------------------ Add User ---------------------------------------------------//
void UserList::addUser(const User& u)
{
    if(usersCount<capacity)
    {
        users[usersCount]=u;
        //This line is used because when you call the parameterized constructor of the UserList class, it also calls the default constructor of the User class. The User count then increases by the number of capacities you have entered, so you must reset it.
        users[usersCount].setId(usersCount+1);
        usersCount++;
    }
    else
    {
        cout<<"Array is full. You can't add more users. \n";
    }
}
//------------------------------------------------// Add User //---------------------------------------------------//

//------------------------------------------------ Search User ---------------------------------------------------//
User* UserList::searchUser(string name)
{
    for(int i=0; i<=usersCount; i++)
    {
        if(users[i].getName()==name)
        {
//            The return type of the function is a pointer, so you must return an address.
            return &users[i];
        }
    }
//    This line is the reason for using a pointer as the return type of this function.
    return nullptr;
}

User* UserList::searchUser(int id)
{
    for(int i=0; i<usersCount; i++)
    {
        if(users[i].getId()==id)
        {
            return &users[i];
        }
    }
    return nullptr;
}
//------------------------------------------------// Search User //---------------------------------------------------//

//------------------------------------------------ Delete User ---------------------------------------------------//
void UserList::deleteUser(int id)
{
    int index=-1;
    for(int i=0; i<usersCount; i++)
    {
        if(users[i].getId()==id)
        {
            index=i;
            break;
        }
    }
    if (index != -1)
    {
        for(int j=index; j<usersCount-1; j++)
        {
            users[j]=users[j+1];
            users[j].setId(j+1);
        }
        usersCount--;
        capacity--;
    }
}
//------------------------------------------------// Delete User //---------------------------------------------------//
//------------------------------------------------ Operator Overloading ---------------------------------------------------//
ostream &operator<<(ostream &output,const UserList &userList)
{
    for(int i=0; i<userList.usersCount; i++)
    {
        output<<userList.users[i];
    }
    return output;
}
//------------------------------------------------// Operator Overloading //---------------------------------------------------//

