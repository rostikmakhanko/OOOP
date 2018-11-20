#include "book.hpp"

using namespace std;

void Book :: print_info()
{
    cout<<title<<endl;
    cout<<short_annotation<<endl;
    cout<<"Authors: ";
    for (int i=0;i<authors.size();i++)
        if (i==authors.size()-1) cout<<authors[i]<<" ";
        else cout<<authors[i]<<", ";
    cout<<endl;
    cout<<"Published: "<<day<<"."<<month<<"."<<year<<endl;
    cout<<"Number of pages: "<<number_of_pages<<endl;
    cout<<endl;
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

