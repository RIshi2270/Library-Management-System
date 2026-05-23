#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

class Book
{
public:
    int id;
    string name;
    string author;
    int quantity;
};

void addBook()
{
    Book b;

    cout << "\nEnter Book ID: ";
    cin >> b.id;

    cout << "Enter Book Name: ";
    cin >> b.name;

    cout << "Enter Author Name: ";
    cin >> b.author;

    cout << "Enter Quantity: ";
    cin >> b.quantity;

    ofstream file("books.txt", ios::app);

    file << b.id << " "
         << b.name << " "
         << b.author << " "
         << b.quantity << endl;

    file.close();

    cout << "\nBook Added Successfully!\n";
}

void viewBooks()
{
    ifstream file("books.txt");

    Book b;

    cout << "\n===== BOOK RECORDS =====\n";

    while(file >> b.id >> b.name >> b.author >> b.quantity)
    {
        cout << "\nBook ID: " << b.id << endl;
        cout << "Book Name: " << b.name << endl;
        cout << "Author: " << b.author << endl;
        cout << "Quantity: " << b.quantity << endl;
    }

    file.close();
}

void searchBook()
{
    ifstream file("books.txt");

    int searchId;
    bool found = false;

    cout << "\nEnter Book ID to Search: ";
    cin >> searchId;

    Book b;

    while(file >> b.id >> b.name >> b.author >> b.quantity)
    {
        if(b.id == searchId)
        {
            cout << "\n===== BOOK FOUND =====\n";

            cout << "Book ID: " << b.id << endl;
            cout << "Book Name: " << b.name << endl;
            cout << "Author: " << b.author << endl;
            cout << "Quantity: " << b.quantity << endl;

            found = true;
            break;
        }
    }

    if(found == false)
    {
        cout << "\nBook Not Found!\n";
    }

    file.close();
}

void deleteBook()
{
    ifstream file("books.txt");
    ofstream tempFile("temp.txt");

    int deleteId;
    bool found = false;

    cout << "\nEnter Book ID to Delete: ";
    cin >> deleteId;

    Book b;

    while(file >> b.id >> b.name >> b.author >> b.quantity)
    {
        if(b.id == deleteId)
        {
            found = true;
            continue;
        }

        tempFile << b.id << " "
                 << b.name << " "
                 << b.author << " "
                 << b.quantity << endl;
    }

    file.close();
    tempFile.close();

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if(found)
    {
        cout << "\nBook Deleted Successfully!\n";
    }
    else
    {
        cout << "\nBook Not Found!\n";
    }
}

void issueBook()
{
    ifstream file("books.txt");
    ofstream tempFile("temp.txt");

    int issueId;
    bool found = false;

    cout << "\nEnter Book ID to Issue: ";
    cin >> issueId;

    Book b;

    while(file >> b.id >> b.name >> b.author >> b.quantity)
    {
        if(b.id == issueId)
        {
            found = true;

            if(b.quantity > 0)
            {
                b.quantity--;

                cout << "\nBook Issued Successfully!\n";
            }
            else
            {
                cout << "\nBook Out of Stock!\n";
            }
        }

        tempFile << b.id << " "
                 << b.name << " "
                 << b.author << " "
                 << b.quantity << endl;
    }

    file.close();
    tempFile.close();

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if(found == false)
    {
        cout << "\nBook Not Found!\n";
    }
}

void returnBook()
{
    ifstream file("books.txt");
    ofstream tempFile("temp.txt");

    int returnId;
    bool found = false;

    cout << "\nEnter Book ID to Return: ";
    cin >> returnId;

    Book b;

    while(file >> b.id >> b.name >> b.author >> b.quantity)
    {
        if(b.id == returnId)
        {
            found = true;

            b.quantity++;

            cout << "\nBook Returned Successfully!\n";
        }

        tempFile << b.id << " "
                 << b.name << " "
                 << b.author << " "
                 << b.quantity << endl;
    }

    file.close();
    tempFile.close();

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if(found == false)
    {
        cout << "\nBook Not Found!\n";
    }
}

int main()
{
    int choice;

    while(true)
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";

        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            addBook();
        }
        else if(choice == 2)
        {
            viewBooks();
        }
        else if(choice == 3)
        {
            searchBook();
        }
        else if(choice == 4)
        {
            deleteBook();
        }
        else if(choice == 5)
        {
            issueBook();
        }
        else if(choice == 6)
        {
            returnBook();
        }
        else if(choice == 7)
        {
            cout << "\nProgram Exited\n";
            break;
        }
        else
        {
            cout << "\nInvalid Choice\n";
        }
    }

    return 0;
}