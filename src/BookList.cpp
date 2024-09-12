#include "BookList.h"

//------------------------------------------------ Constructors & Destructor ---------------------------------------------------//
BookList::BookList():capacity(0),booksCount(0) {}
BookList::BookList(int capacity)
{
    this->capacity=capacity;
    booksCount=0;
    //This line will call the default constructor of the Book class with the specified capacity.
    books=new Book[capacity];
}
BookList::~BookList()
{
    delete [] books;
}
BookList::BookList(const BookList &book)
{
    /////////////////

}
//------------------------------------------------// Constructors & Destructor //---------------------------------------------------//

//------------------------------------------------ Add Book ---------------------------------------------------//
void BookList::addBook(Book &book)
{
    if(booksCount<capacity)
    {
        books[booksCount]=book;
        books[booksCount].setId(booksCount+1);
        booksCount++;
    }
    else
    {
        cout<<"Array is full. You can't add more books. \n";
    }
}
//------------------------------------------------// Add Book //---------------------------------------------------//

//------------------------------------------------ Search Book ---------------------------------------------------//
Book* BookList::searchBook(string name)
{
    for(int i=0; i<booksCount; i++)
    {
        if(name==books[i].getTitle())
        {
            return &books[i];
        }
    }
    return nullptr;
}

Book* BookList::searchBook(int id)
{
    for(int i=0; i<booksCount; i++)
    {
        if(id==books[i].getId())
        {
            return &books[i];
        }
    }
    return nullptr;
}
//------------------------------------------------// Search Book //---------------------------------------------------//

//------------------------------------------------ Delete Book ---------------------------------------------------//
void BookList::deleteBook(int id)
{
    int index=-1;
    for(int i=0; i<booksCount; i++)
    {
        if(id==books[i].getId())
        {
            index=i;
            break;
        }
    }
    if (index != -1)
    {
        for(int i=index; i<booksCount-1; i++)
        {
            books[i]=books[i+1];
            books[i].setId(i+1);
        }
        booksCount--;
        capacity--;
    }
}
//------------------------------------------------// Delete Book //---------------------------------------------------//

//------------------------------------------------ Operator Overloading ---------------------------------------------------//
ostream &operator<<(ostream &output,const BookList &bookList)
{
    for(int i=0; i<bookList.booksCount; i++)
    {
        output<<bookList.books[i];
    }
    return output;
}
//------------------------------------------------// Operator Overloading //---------------------------------------------------//

//------------------------------------------------ Get the highest rated book function ---------------------------------------------------//
Book BookList::getTheHighestRatedBook()
{
    double highest_rate=-1.0;
    int highest_rate_index=0;
    for(int i=0; i<booksCount; i++)
    {
        if(books[i].getAverageRating()>=highest_rate)
        {
            highest_rate=books[i].getAverageRating();
            highest_rate_index=i;
        }
    }
    return books[highest_rate_index];
}
//------------------------------------------------// Get the highest rated book function //---------------------------------------------------//

//------------------------------------------------ Get books for user function ---------------------------------------------------//
void BookList::getBooksForUser(User& user)
{
    bool found=false;
    for(int i=0; i<booksCount; i++)
    {
        if(books[i].getAuthor()==user)
        {
            found=true;
            cout<<books[i];
        }
    }
    if(!found)
    {
        cout<<"No books have this author \n";
    }
}
//------------------------------------------------// Get books for user function //---------------------------------------------------//

//------------------------------------------------ Work with an object like an array ---------------------------------------------------//
Book& BookList::operator[](int position)
{
    if(position<0||position>=booksCount)
    {
        cout<<"Position error \n";
        exit(1);
    }
    return books[position];
}
//------------------------------------------------// Work with an object like an array //---------------------------------------------------//
