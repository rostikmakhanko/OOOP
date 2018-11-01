#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

class Program
{
private:
	int type;

	public:
    Program()
    {

    }

	Program(int type)
	{
		this->type = type;
	}
};

class Message
{
private:
	int size;
	string type;

public:
    Message()
    {

    }

	Message(int size, string type)
	{
		this->size = size;
		this->type = type;
	}

	int get_size()
	{
	    return size;
	}
};

class Server
{
private:
	Program* program;
	int index;
	int received,sent;
    vector<pair<int,int>> neighbours;//first - index of neighbour server, second - speed

public:
    Server()
    {

    }

	Server(Program* program,int index) {
	    this->index=index;
		this->program=program;
		received=sent=0;
	}

	void connect_with(int x,int s)
	{
	    neighbours.push_back(make_pair(x,s));
	}

	vector<pair<int,int>> get_neighbours()
	{
	    return neighbours;
	}

	int get_speed(int m)
	{
	    for (int i=0;i<neighbours.size();i++)
            if (neighbours[i].first==m) return neighbours[i].second;
        return -1;
	}

	void receive()
	{
	    received++;
	}

	void send()
	{
	    sent++;
	}

	int get_received()
	{
	    return received;
	}

	int get_sent()
	{
	    return sent;
	}
};

class Network
{
private:
	int size;
	vector <Server*> servers;
	bool used[200005];
	int prev[200005];

	void dfs_prepparation()
	{
	    for (int i=0;i<size;i++)
        {
            used[i]=0;
            prev[i]=-1;
        }
	}

	bool can_dfs(int x,int m)
	{
	    if (x==m) {return 1;}
	    used[x]=1;
	    vector<pair<int,int>> cur=servers[x]->get_neighbours();
        for (int i=0;i<cur.size();i++)
            if (!used[cur[i].first]) {can_dfs(cur[i].first,m);}
	}

	void dfs(int x,int m,int prev1)
	{
	    if (x==m) {prev[x]=prev1; return;}
	    used[x]=1;
	    vector<pair<int,int>> cur=servers[x]->get_neighbours();
        for (int i=0;i<cur.size();i++)
            if (!used[cur[i].first]) {dfs(cur[i].first,m,x);}
        prev[x]=prev1;
	}

	vector<int> build_dfs_way(int m)
	{
	    vector<int> dfs_way;
	    int m1=m;
	    while (m1!=-1)
        {
            dfs_way.push_back(m1);
            m1=prev[m1];
        }
        reverse(dfs_way.begin(),dfs_way.end());
        return dfs_way;
	}

	void send_message_to_neighbour(Message* message, int from, int to)
    {
        cout<<"Server "<<from<<" sends message to "<<to<<endl;
        servers[from]->send();
        int speed=servers[from]->get_speed(to);
        Sleep((message->get_size())/speed);
        servers[to]->receive();
        cout<<"Server "<<to<<" got message from "<<from<<endl;
    }

	public:

	Network()
	{
		size=0;
	}

    int get_size()
    {
        return size;
    }

    void connect(int x,int y,int s)//x,y - indexes of connected servers, s - speed
    {
        if (x==y) {return;}
        servers[x]->connect_with(y,s);
        servers[y]->connect_with(x,s);
    }

	void addServer(Program* program)
	{
		servers.push_back(new Server(program,size));
		size++;
	}

	void sendMessage(Message* message,int from,int to) {
	    dfs_prepparation();
        if (!can_dfs(from,to))
        {
            cout<<"Unfortunately, can't send message from server "<<from<<" to "<<to<<endl;
            cout<<endl;
        }
        else
        {
            cout<<"Starts process of sending message from server "<<from<<" to "<<to<<": "<<endl;
            dfs_prepparation();
            dfs(from,to,-1);
            vector<int> w=build_dfs_way(to);
            for (int i=0;i<w.size()-1;i++)
                send_message_to_neighbour(message,w[i],w[i+1]);
            cout<<"Message successfully sent from server "<<from<<" to "<<to<<"!"<<endl;
            cout<<endl;
        }
	}

	vector<int> sortBy(int q)//q==0 - by received, 1 - by sent, else - by all
	{
	    int n=servers.size();
	    vector<pair<int,int>> x;
        if (q==0)
        {
            for (int i=0;i<n;i++)
                x.push_back(make_pair(servers[i]->get_received(),i));
        }
        else if (q==1)
        {
            for (int i=0;i<n;i++)
                x.push_back(make_pair(servers[i]->get_sent(),i));
        }
        else
        {
            for (int i=0;i<n;i++)
                x.push_back(make_pair(servers[i]->get_received()+servers[i]->get_sent(),i));
        }
        sort(x.begin(),x.end());
        vector<int> ans;
        for (int i=0;i<n;i++)
            ans.push_back(x[i].second);
        return ans;
	}
};

int main()
{
	Network network;

	network.addServer(new Program(1));
	network.addServer(new Program(3));
	network.addServer(new Program(3));
	network.addServer(new Program(2));
	network.addServer(new Program(2));
	network.addServer(new Program(2));

    network.connect(0,2,10);
    network.connect(4,2,1);
    network.connect(1,2,100);
    network.connect(3,2,150);
    network.connect(1,3,1);

	network.sendMessage(new Message(1000,"txt"),0,1);
	network.sendMessage(new Message(5000,"doc"),0,2);
	network.sendMessage(new Message(5000,"cpp"),4,3);
	network.sendMessage(new Message(5000,"cpp"),5,2);

	vector<int> a=network.sortBy(0);
	cout<<"Servers sorted by received messages(first-min,last-max):"<<endl;
	for (int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
    a=network.sortBy(1);
	cout<<"Servers sorted by sent messages(first-min,last-max):"<<endl;
	for (int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
