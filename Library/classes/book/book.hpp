#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>
#include "character/character.hpp"

using namespace std;

class Book
{
private:
    string title;
    vector<string> authors;
    int day,month,year;
    int number_of_pages;
    string short_annotation;

public:
    friend bool operator>(const Book& a,const Book& b);
    friend bool operator<(const Book& a,const Book& b);
    friend bool operator==(const Book& a,const Book& b);

    void print_info();
    void set_title(string);
    void add_author(string);
    void set_day(int);
    void set_month(int);
    void set_year(int);
    void set_number_of_pages(int);
    void set_short_annotation(string);
    void clear();

    string get_title();
    vector<string> get_authors();
    int get_day();
    int get_month();
    int get_year();
    int get_number_of_pages();
    string get_short_annotation();

};

#endif // BOOK_H
