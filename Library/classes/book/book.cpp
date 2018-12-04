#include "book.hpp"

using namespace std;

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

void Book::set_title(string s)
{
    title=s;
}

string Book::get_title()
{
    return title;
}

void Book::add_author(string s)
{
    authors.push_back(s);
}

vector<string> Book::get_authors()
{
    return authors;
}

int Book::get_day()
{
    return day;
}

void Book::set_day(int val)
{
    day=val;
}

int Book::get_month()
{
    return month;
}

void Book::set_month(int val)
{
    month=val;
}

int Book::get_year()
{
    return year;
}

void Book::set_year(int val)
{
    year=val;
}

int Book::get_number_of_pages()
{
    return number_of_pages;
}

void Book::set_number_of_pages(int val)
{
    number_of_pages=val;
}

string Book::get_short_annotation()
{
    return short_annotation;
}

void Book::set_short_annotation(string s)
{
    short_annotation=s;
}

void Book::clear()
{
    authors.clear();
}

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
