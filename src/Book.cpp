#include "Book.h"
int Book::count=0;

//------------------------------------------------ Constructors ---------------------------------------------------//
Book::Book():title(""),isbn(""),id(++count),category(""),averageRating(0.0),numOfRates(0),sumOfRates(0.0)
{
//    User author;//This line calls the default constructor of the User class to initialize its values. (Use this line if you created the object normally (not via a pointer).)
//    author=new User();//(Use this line if you created the object via pointer)
}
//Book::~Book()
//{
//    // Clean up dynamically allocated memory
//    delete author;
//}

Book::Book(string t, string bn, string c):title(t),isbn(bn),category(c),numOfRates(0),sumOfRates(0.0)
{
    count++;
    id=count;
    averageRating=0.0;
//    User author;//This line calls the default constructor of the User class to initialize its values.
}
Book::Book(const Book&b)
{
    title=b.title;
    isbn=b.isbn;
    id=b.id;
    category=b.category;
    author=b.author;
    averageRating=b.averageRating;
    numOfRates=b.numOfRates;
    sumOfRates=b.sumOfRates;
}
//------------------------------------------------// Constructors //---------------------------------------------------//

//------------------------------------------------ Setters ---------------------------------------------------//
void Book::setTitle(string title)
{
    // 'this' pointer refers to the current instance of the Book class
    this->title=title;
}
void Book::setISBN(string isbn)
{
    this->isbn=isbn;
}
void Book::setId(int id)
{
    this->id=id;
}
void Book::setCategory(string category)
{
    this->category=category;
}
void Book::setAuthor(const User& u)
{

//    author=new User(u);//this line calls the copy constructor of user class
    author=u;
}
//------------------------------------------------// Setters //---------------------------------------------------//

//------------------------------------------------ Getters ---------------------------------------------------//
string Book::getTitle() const
{
    return title;
}
string Book::getISBN() const
{
    return isbn;
}
int Book::getId() const
{
    return id;
}
string Book::getCategory() const
{
    return category;
}
double Book::getAverageRating()const
{
    return averageRating;
}
User Book::getAuthor() const
{
    return author;
}
//------------------------------------------------// Getters //---------------------------------------------------//

//------------------------------------------------ Overloading (==) Operator ---------------------------------------------------//
bool Book::operator==(const Book &b)
{
    return (title==b.title&&isbn==b.isbn&&id==b.id&&category==b.category&&averageRating==b.averageRating&&author==b.author);
}
//------------------------------------------------// Overloading (==) Operator //---------------------------------------------------//

//------------------------------------------------ Overloading stream operators ---------------------------------------------------//
istream& operator>>(istream& input,Book& b)
{
    cout<<"\t\t\t\t\t\t Enter the Book information \n";
    cout<<"Enter the title: ";
    input>>b.title;
    cout<<"Enter the isbn: ";
    input>>b.isbn;
    cout<<"Enter the category: ";
    input>>b.category;
    cout<<"\n";
    return input;
}

ostream& operator<<(ostream& output,const Book&b)
{
    output<<"========== Book["<<b.id<<"]"<<" Info =========="<<'\n';
    output<<"Title: "<<b.title;
    output<<" | Isbn: "<<b.isbn;
    output<<" | Id: "<<b.id;
    output<<" | Category: "<<b.category;
    output<<" | Rating: "<<b.averageRating;
    if(b.getAuthor().getName()!="")
    {
//        When output << b.author is executed, it invokes the overloaded << operator for the User class.
        output<<b.author;
    }
    cout<<"\n================================================================================================="<<'\n'<<'\n';
    return output;
}
//------------------------------------------------// Overloading stream operators //---------------------------------------------------//

//------------------------------------------------ Rate a book ---------------------------------------------------//
void Book::rateBook(double rating)
{
    numOfRates++;
    sumOfRates+=rating;
    averageRating=sumOfRates/numOfRates;
}
//------------------------------------------------// Rate a book //---------------------------------------------------//
