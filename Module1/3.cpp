#include <bits/stdc++.h>

using namespace std;

int S;

class Base
{
protected:
    static int N;
    int n;

public:
    Base()
    {
        N++;
        n=N;
        //cout<<"Constructor of Beta for element "<<n<<endl;
    }

    virtual ~Base()
    {
        //cout<<"Destructor of Base for element "<<n<<endl;
        S=3*S+N-19;
    }

    int get_n()
    {
        return N;
    }
};

int Base::N=0;

class Alpha:public Base
{
public:
    Alpha():Base()
    {
        //cout<<"Constructor of Alpha for element "<<n<<endl;
    }

    ~Alpha()
    {
        //cout<<"Destructor of Alpha for element "<<n<<endl;
        S=S/3-N;
    };
};

class Beta:public Base
{
public:
    Beta():Base()
    {
        //cout<<"Constructor of Beta for element "<<n<<endl;
    }

    ~Beta()
    {
        //cout<<"Destructor of Beta for element "<<n<<endl;
        S=S+2*N+5;
    };
};

class Red:public Alpha
{
public:
    Red():Alpha()
    {
        //cout<<"Constructor of Red for element "<<n<<endl;
    }

    ~Red()
    {
        //cout<<"Destructor of Red for element "<<n<<endl;
        S=S-N/2;
    };
};

class Green:public Alpha
{
public:
    Green():Alpha()
    {
        //cout<<"Constructor of Green for element "<<n<<endl;
    }

    ~Green()
    {
        //cout<<"Destructor of Green for element "<<n<<endl;
        S=S-N/2-4;
    };
};

int predict_S(vector<Base*> cur)//2
{
    int S1=S;//remember S
    int n=cur.size();
    for (int i=0;i<n;i++)
    {
        int n1=cur[i]->get_n();
        if (dynamic_cast<Green*>(cur[i]))
        {
            S=S-n1/2-4;
            S=S/3-n1;
            S=3*S+n1-19;
        }
        else if (dynamic_cast<Red*>(cur[i]))
        {
            S=S-n1/2;
            S=S/3-n1;
            S=3*S+n1-19;
        }
        else if (dynamic_cast<Beta*>(cur[i]))
        {
            S=S+2*n1+5;
            S=3*S+n1-19;
        }
        else if (dynamic_cast<Alpha*>(cur[i]))
        {
            S=S/3-n1;
            S=3*S+n1-19;
        }
        else
        {
            S=3*S+n1-19;
        }
    }
    int ans=S;//remember answer
    S=S1;//update S to old version
    return ans;
}

int g[15];

//3
void generating(int pos,int n,int k)//all combinations for n elements
{
	if (pos==n)
    {
		for (int i=0;i<n;i++)
		{
		    int S1=S;//remember S
			vector<Base*> a;
            for (int i=0;i<n;i++)
            {
                int k=g[i];
                if (k%5==0)
                {
                    a.push_back(new Base());
                }
                else if (k%5==1)
                {
                    a.push_back(new Alpha());
                }
                else if (k%5==2)
                {
                    a.push_back(new Beta());
                }
                else if (k%5==3)
                {
                    a.push_back(new Red());
                }
                else
                {
                    a.push_back(new Green());
                }
            }
        for (int i=0;i<a.size();i++)
        {
            delete a[i];
        }
        cout<<S<<endl;//print waiting value of S for this combination of n elements
        S=S1;//update S to old version
		}
		return;
	}
	for (int i=0;i<k;i++)
	{
		g[pos]=i;
		generating(pos+1,n,k);
	}
}

int main()
{
    //1
    S=0;
    srand(time(0));
    int n=rand()%100+1;
    vector<Base*> a;
    for (int i=0;i<n;i++)
    {
        int k=rand()%5;
        if (k%5==0)
        {
            a.push_back(new Base());
        }
        else if (k%5==1)
        {
            a.push_back(new Alpha());
        }
        else if (k%5==2)
        {
            a.push_back(new Beta());
        }
        else if (k%5==3)
        {
            a.push_back(new Red());
        }
        else
        {
            a.push_back(new Green());
        }
    }
    int pr=predict_S(a);
    for (int i=0;i<n;i++)
    {
        delete a[i];
    }
    cout<<S<<" "<<pr<<endl;//print S after deleting elements of a and predictable value of S
    int M=4;
    generating(0,M,5);
    return 0;
}
