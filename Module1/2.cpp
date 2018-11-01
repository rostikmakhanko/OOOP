#include <bits/stdc++.h>

using namespace std;

pair<string,int> f(int x)
{
    if (x>=0)
    {
        int sec=1;
        for (int i=0;i<x;i++)
            sec=(sec*2)%119;
        sec=(sec+x*x)%119;
        return make_pair("red",sec);
    }
    else
    {
        int sec=1;
        for (int i=0;i<5;i++)
            sec=(sec*x)%219;
        sec=(sec+x-1)%219;
        return make_pair("green",sec);
    }
}

pair<string,int> f(double x)
{
    int sec=((int)(1/sin(log2(x))))%319;
    return make_pair("blue",sec);
}

pair<string,int> f(string s)
{
    int n=s.size(),k=0,sec=0;
    for (int i=0;i<n;i++)
        if (s[i]==' ')
        {
            if (k>=4&&k<=7) sec++;
            k=0;
        }
        else
        {
            k++;
        }
    if (s[n-1]!=' '&&k>=4&&k<=7) sec++;
    return make_pair("green",sec);
}

string third(string a,string b)
{
    if (a==b) return a;
    if (a=="green"&&b=="red") return "blue";
    if (b=="green"&&a=="red") return "blue";
    if (a=="green"&&b=="blue") return "red";
    if (b=="green"&&a=="blue") return "red";
    if (a=="red"&&b=="blue") return "green";
    return "green";
}

pair<string,int> f(pair<string,int> a,pair<string,int> b)
{
    int sec=1,fa=f((int)(a.second)).second,fb=f((int)(b.second)).second;
    for (int i=0;i<fb;i++)
        sec=(sec*fa)%519;
    return make_pair(third(a.first,b.first),sec);
}

pair<string,int> f(vector<pair<string,int>> x)
{
    int sec=0,n=x.size();
    for (int i=0;i<n;i++)
    {
        sec=(sec+f(x[i].second).second*f(x[n-i-1].second).second)%719;
    }
    int kb=0,kr=0,kg=0;
    string fir;
    for (int i=0;i<n;i++)
        if (x[i].first=="blue")
        {
            kb++;
            if (kb>=kr&&kb>=kg) fir="blue";
        }
        else if (x[i].first=="red")
        {
            kr++;
            if (kr>=kb&&kr>=kg) fir="red";
        }
        else
        {
            kg++;
            if (kg>=kb&&kg>=kr) fir="green";
        }
    return make_pair(fir,sec);
}

template <typename T>
pair<string,int> f(T x)
{
    return make_pair("red",8359);
}

int main()
{
    pair<string,int> f1;
    int n=10;
    f1=f(n);
    cout<<f1.first<<" "<<f1.second<<endl;
    n=143;
    f1=f(n);
    cout<<f1.first<<" "<<f1.second<<endl;
    n=-3343;
    f1=f(n);
    cout<<f1.first<<" "<<f1.second<<endl;
    double d=24.594439;
    f1=f(d);
    cout<<f1.first<<" "<<f1.second<<endl;
    string s="dsas asdsaads sds saw wwadwa sadd";
    f1=f(s);
    cout<<f1.first<<" "<<f1.second<<endl;
    pair<string,int> a=make_pair("red",8),b=make_pair("green",-345);
    f1=f(a,b);
    cout<<f1.first<<" "<<f1.second<<endl;
    vector<pair<string,int>> v;
    for (int i=0;i<10;i++)
        if (i%3==2) v.push_back(make_pair("red",i*13));
        else v.push_back(make_pair("blue",i*5+4));
    f1=f(v);
    cout<<f1.first<<" "<<f1.second<<endl;
    queue<int> q;
    q.push(1); q.push(3); q.push(5);
    f1=f(q);
    cout<<f1.first<<" "<<f1.second<<endl;
    return 0;
}
