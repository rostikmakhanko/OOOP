#include "character.hpp"

using namespace std;

/**
    Convert int value of role to string

    @param x - type in integer format
    @return String representation of role type
*/
string Character :: get_type_of_role(int x)
{
    if (x==0) return "main role";
    if (x==1) return "supporting role";
    if (x==2) return "episode role";
}

/**
    Adding name or nickname for character

    @param One string s - name or nickname
*/
void Character :: add_name(string s)
{
    names.push_back(s);
}

/**
    Adding book in which this character is playing role

    @param s - title of book, t - type of role
*/
void Character :: add_book(string s,int t)
{
    books.push_back(make_pair(s,t));
}

///Clearing information about character
void Character :: clear()
{
    names.clear();
    books.clear();
}


///Print information about character
void Character :: print_info()
{
    cout<<names[0]<<" ";
    if (names.size()>0)
    {
        cout<<"also known as ";
        for (int i=1;i<names.size();i++)
            if (i==names.size()-1) cout<<names[i]<<" ";
            else cout<<names[i]<<", ";
    }
    cout<<"mentioned in books:"<<endl;
    for (int i=0;i<books.size();i++)
        cout<<books[i].first<<" - "<<get_type_of_role(books[i].second)<<endl;
    cout<<endl;
};
