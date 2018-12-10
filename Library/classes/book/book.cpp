#include "book.hpp"

using namespace std;

///Print information about book
void Book :: print_info()
{
    cout<<title<<endl;
    cout<<short_annotation<<endl;
    cout<<"Authors: ";
    for (int i=0;i<(int)authors.size();i++)
        if (i==(int)authors.size()-1) cout<<authors[i]<<" ";
        else cout<<authors[i]<<", ";
    cout<<endl;
    cout<<"Published: "<<day<<"."<<month<<"."<<year<<endl;
    cout<<"Number of pages: "<<number_of_pages<<endl;
    cout<<endl;
}

/**
    Set title of book

    @param One string s - title of book
*/
void Book::set_title(string s)
{
    title=s;
}

/**
    Get title of book

    @return One string s - title of book
*/
string Book::get_title()
{
    return title;
}

/**
    Add title of book

    @param One string s - name of author
*/
void Book::add_author(string s)
{
    authors.push_back(s);
}

/**
    Get authors of book

    @return Vector of strings - names of authors
*/
vector<string> Book::get_authors()
{
    return authors;
}

/**
    Set day of publishing for book

    @param One integer in range [1,31] - day of publishing
*/
void Book::set_day(int val)
{
    day=val;
}

/**
    Get day of publishing for book

    @return One integer in range [1,31] - day of publishing
*/
int Book::get_day()
{
    return day;
}

/**
    Set month of publishing for book

    @param One integer in range [1,12] - month of publishing
*/
void Book::set_month(int val)
{
    month=val;
}

/**
    Get month of publishing for book

    @return One integer in range [1,12] - month of publishing
*/
int Book::get_month()
{
    return month;
}

/**
    Set year of publishing for book

    @return One integer - month of publishing
*/
void Book::set_year(int val)
{
    year=val;
}

/**
    Get year of publishing for book

    @return One integer - month of publishing
*/
int Book::get_year()
{
    return year;
}

/**
    Set number of pages for book

    @param One integer val - number of pages
*/
void Book::set_number_of_pages(int val)
{
    number_of_pages=val;
}

/**
    Get number of pages for book

    @return One integer - number of pages
*/
int Book::get_number_of_pages()
{
    return number_of_pages;
}

/**
    Set annotation for book

    @param One string s - short annotation
*/
void Book::set_short_annotation(string s)
{
    short_annotation=s;
}

/**
    Get annotation for book

    @return One string - short annotation
*/
string Book::get_short_annotation()
{
    return short_annotation;
}

///Clear information about book
void Book::clear()
{
    authors.clear();
}

/**
    Overloading operators for Book, comparing by the title
*/
bool operator>(const Book& a,const Book& b)
{
    return a.title>b.title;
}

bool operator<(const Book& a,const Book& b)
{
    return a.title<b.title;
}

bool operator==(const Book& a,const Book& b)
{
    return a.title==b.title;
}
