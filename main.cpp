#include <iostream>
using namespace std;

class Book
{
public:
    int id;
    string name;
    string author;
    int quantity;
};

int main()
{
    Book b1;

    b1.id = 101;
    b1.name = "C++";
    b1.author = "Bjarne";
    b1.quantity = 5;

    cout << "Book ID: " << b1.id << endl;
    cout << "Book Name: " << b1.name << endl;
    cout << "Author: " << b1.author << endl;
    cout << "Quantity: " << b1.quantity << endl;

    return 0;
}