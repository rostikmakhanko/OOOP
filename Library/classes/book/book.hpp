#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>
#include "character/character.hpp"

using namespace std;

class Book
{
public://!!!!!!!!!!!!!!!!!!!!!!it must be private
    string title;
    vector<string> authors;
    int day,month,year;
    int number_of_pages;
    string short_annotation;
    vector<Character> characters;

public:
    friend bool operator>(const Book& a,const Book& b);
    friend bool operator<(const Book& a,const Book& b);
    friend bool operator==(const Book& a,const Book& b);

    void print_info();
};

#endif // BOOK_H
