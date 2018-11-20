#include "character.hpp"

using namespace std;

string Character :: get_type_of_role(int x)
{
    if (x==0) return "main role";
    if (x==1) return "supporting role";
    if (x==2) return "episode role";
}

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
