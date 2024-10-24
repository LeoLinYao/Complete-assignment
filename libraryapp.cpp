//Copyright (c) 2024 [Yao Lin]
//Description: This is a brief library management system for users to add, delete, search, check out, return books.
//And it can list all existed books, users can save/load data via books database.


#include "library.h"
#include <iostream>
#include <fstream>
using namespace std;

void printMenu(){
     cout << "Welcome to the simple library information system" << endl;
     cout << "Please enter your selection:" << endl;
     cout << "1.Add a book" << endl;
     cout << "2.Delete a book" << endl;
     cout << "3.Search for a book" << endl;
     cout << "4.Check out a book" << endl;
     cout << "5.return a book" << endl;
     cout << "6.List all books" << endl;
     cout << "7.Load from books database" << endl;
     cout << "8.Save in books database" << endl;
     cout << "9.Exit" << endl;
}    

int main() {

    Operation librarySystem;
    
    int selection;
    string title;
    string author;
    string genre;

    do {
        printMenu();
        cin >> selection;
        cin.ignore();
     switch (selection) {
            case 1:
                cout << "Enter the title of the book: ";
                getline(cin, title);
                cout << "Enter the author of the book: ";
                getline(cin, author);
                cout << "Enter the genre of the book: ";
                getline(cin, genre);
                librarySystem.adding(title, author, genre);
                break;

            case 2:
                cout << "Enter the title of the book to delete: ";
                getline(cin, title);
                librarySystem.deleting(title);
                break;

            case 3:
                cout << "Enter the title of the book to search: ";
                getline(cin, title);
                librarySystem.searching(title);
                break;

            case 4:
                cout << "Enter the title of the book to check out: ";
                getline(cin, title);
                librarySystem.checkout(title);
                break;

            case 5:
                cout << "Enter the title of the book to return: ";
                getline(cin, title);
                librarySystem.returnbook(title);
                break;

            case 6:
                librarySystem.list();
                break;

            case 7:
                librarySystem.loadfrombooksdb();
                break;

            case 8:
                librarySystem.saveinbooksdb();
                break;

            case 9:
                cout << "Exiting the Librarysystem." << endl;
                break;
        }

    } while (selection != 9);

    return 0;
}
