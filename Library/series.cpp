#include "series.h"

using namespace std;

Series :: Series(BinarySearchTree &t,vector<Character> &c)
{
    int n=c.size(),count_of_series=0;
    map<string,int> x;//x[s]=a - book with title s is part of series number a
    for (int i=0;i<n;i++)
    {
        int m=c[i].books.size(),number_of_series=1e9+7;//number_of_series - number of series in which all books where play i-th character will go
        for (int j=0;j<m;j++)
        {
            if (c[i].books[j].second==2) {continue;}
            if (x[c[i].books[j].first]!=0)
            {
                number_of_series=min(x[c[i].books[j].first],number_of_series);
            }
        }
        if (number_of_series==1e9+7)
        {
            count_of_series++;
            for (int j=0;j<m;j++)
            {
                if (c[i].books[j].second==2) {continue;}
                x[c[i].books[j].first]=count_of_series;
            }
        }
        else
        {
            for (int j=0;j<m;j++)
            {
                if (c[i].books[j].second==2) {continue;}
                x[c[i].books[j].first]=number_of_series;
            }
        }
    }
    //all books which do not have main or supporting characters are moving to new series, for each book is it's own series
    vector<string> all_books=t.get_books_titles();
    for (int i=0;i<all_books.size();i++)
        if (x[all_books[i]]==0)
        {
            count_of_series++;
            x[all_books[i]]=count_of_series;
        }
    vector<vector<string>> series1(count_of_series+1);
    for (map<string,int>::iterator it=x.begin();it!=x.end();++it)
    {
        series1[it->second].push_back(it->first);
    }
    series=series1;
}

void Series :: print()
{
    cout<<"All book series in library:"<<endl;
    for (int i=1;i<series.size();i++)
    {
        cout<<"Series #"<<i<<": ";
        for (int j=0;j<series[i].size();j++)
            cout<<series[i][j]<<(j==series[i].size()-1?" ":", ");
        cout<<endl;
    }
    cout<<"-------------------------------------"<<endl;
    cout<<endl;
}
