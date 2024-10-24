#ifndef LIBRARY_H
#define LIBRARY_H
// This header file should include variables for storing book information (such as 
// title, author, genre, availability) and functions for operations like adding, 
// deleting, searching for books, and managing checkouts and returns.
// No implementation details should be in the header file.
// Make sure you revise this comment section to reflect your work.
#include <fstream>
#include<string> 
using namespace std;


using std::string;


class Bookinfo{
public:    
    string title;
    string author;
    string genre;
    bool availability;

    Bookinfo() : title(""), author(""), genre(""), availability(true) {}

    Bookinfo(string t, string a, string g, bool av = true) ;
};

class Operation{

public:
    Bookinfo books[10000];
    int count = 0;
    void adding (string title, string author, string genre);
    void deleting(string title);
    void searching(string title);
    void checkout(string title);
    void returnbook(string title);
    void list();
    void loadfrombooksdb();
    void saveinbooksdb();
    Operation();
};


























#endif
