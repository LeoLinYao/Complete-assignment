// provide implementation logic to each library function decalred in library.h
// no main() in this file
#include "library.h"
#include <iostream>
#include <fstream>

using namespace std;

Bookinfo::Bookinfo(string t, string a, string g, bool av) {
    title = t;
    author = a;
    genre = g;
    availability = av;
}

Operation::Operation() {
    count = 0;
}  

void Operation::adding(string title, string author, string genre){
    books[count] = Bookinfo(title, author, genre);
    count++;
    cout << "Add book successfully" << endl;
}

void Operation::deleting(string title){
    for (int i = 0; i < count; i++){
        if (books[i].title == title) {
            for (int j = i; j < count-1; j++){
                books[j] = books[j+1];
            }
            count--;
            cout << "Delete book successfully" << endl;
            return;
        }
    }
    cout << "Not found book" << endl;
}


void Operation::searching(string title){
    for (int i = 0; i < count; i++){
        if (books[i].title == title){
            cout << "Title:" << books[i].title << " Author:" << books[i].author << " Genre:" << books[i].genre << " Is available:" << books[i].availability << endl;
            return;
        }
    }
    cout << "Not found the book" << endl;
}

void Operation::checkout(string title){
    for (int i = 0; i < count; i++){
        if (books[i].title == title){
            if (books[i].availability == true){
                books[i].availability = false;
                cout << "Check out successfully" << endl;
            }else{
                cout << "The book has been checked out" << endl;
            }
            return;
        }
    }
    cout << "Not found the book" << endl;
}

void Operation::returnbook(string title){
     for (int i = 0; i < count; i++){
        if (books[i].title == title){
            if (books[i].availability == false){
                books[i].availability = true;
                cout << "Return successfully" << endl;
            }else{
                cout << "The book has been returned" << endl;
            }
            return;

        }
     }
    cout << "Not found the book" << endl;
}

void Operation::list(){
    for (int i=0; i < count; i++){
        cout << "Title:" << books[i].title << " Author:" << books[i].author << " Genre:" << books[i].genre << " Is available:" << books[i].availability << endl;
    }
}


void Operation::loadfrombooksdb(){
    ifstream file("books.db");
    if (!file) {
        cout << "Error opening file: books.db" << endl;
        return;
    }

    string title;
    string author;
    string genre;
    bool availability;
    while (file >> title >> author >> genre >> availability){
        books[count] = Bookinfo(title, author, genre, availability);
        count++;
    }
    file.close();
    cout << "Books loaded from file" << endl;
}


void Operation::saveinbooksdb() {
    ofstream file("books.db");
    if (!file) {
        cout << "Error opening file: books.db" << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        file << books[i].title << " " << books[i].author << " " << books[i].genre << " " << books[i].availability << endl;
    }
    file.close();
    cout << "Books saved to file" << endl;
}