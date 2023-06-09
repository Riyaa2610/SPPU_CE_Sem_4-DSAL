/*There are fight paths between the cities. If there is a fight between the
city A and city B then there is an edge between the city A to B. The
cost of an edge represents the time required or fuel required to travel
from city A to B. Represent this as a graph using adjacency list where
every node of graph represented by city name. Perform following
operations 1) calculate in degree, out degree of vertices 2) check
whether graph is connected or not.*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class node{
    public:
    string data;
    int id;
    node*next;
    node()
    {
        data = " ";
        id = 0;
        next = NULL;
    }
    node(string value,int i)
    {
        data = value;
        id = i;
        next = NULL;
    }
};

class graph{
    public:
    node *temp,*entry;

    int total; //total vertices
    int no;    //no of vertices connected to one vertex
    string v1_name;
    string v2_name;
    int v1_id;
    int v2_id;
    node*adj[10];
    int*visited;
    int indegree[10];
    int outdegree[10];

    graph()
    {
        for(int i=0;i<10;i++)
        {
            adj[i] = NULL;
        }
    }

    void read()
    {
        cout<<"enter total vertices: ";
        cin>>total;

        for(int i=0;i<total;i++)
        {
            cout<<"enter name of vertex: ";
            cin>>v1_name;
            cout<<"enter id of vertex: ";
            cin>>v1_id;

            temp = new node(v1_name,v1_id);
            adj[i] = temp;

            cout<<"enter the no of vertices connected to "<<i<<" vertex: "; 
            cin>>no;
            indegree[i] = no;
            outdegree[i] = no;
            for(int j=0;j<no;j++)
            {
                cout<<"enter name of adjacent vertex: ";
                cin>>v2_name;
                cout<<"enter id of adjacent vertex: ";
                cin>>v2_id;

                entry = new node(v2_name,v2_id);
                temp->next = entry;
                temp = entry;
            }       
        }
    }

    void display()
    {
        for(int i=0;i<total;i++)
        {
            cout<<i<<" : ";
            temp = adj[i];
            while(temp!=NULL)
            {
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

    void bfs(int key)
    {
        //key here is source node for starting of bfs traversal
        cout<<"\n BFS traversal";
        visited = new int[total];
        for(int i=0;i<total;i++)
        {
            visited[i] = 0;
        }
        queue<node* >q;
        node*curr = NULL;
        int curr_id;
        temp =adj[key];
        visited[key]=1;
        q.push(temp);
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            cout<<" "<<curr->id<<" - "<<curr->data<<" ";
            for(int j=key;j<=total;j++)
            {
                node*ptr = adj[j];
                while(ptr!=NULL)
                {
                    curr_id = ptr->id;
                    if(visited[curr_id] == 0)
                    {
                        q.push(ptr);
                        visited[curr_id] = 1;
                    }
                    ptr = ptr->next;
                }
            }
        } 
        cout<<endl;
    }

    void dfs(int key)
    {
        cout<<"\nDFS traversal";
        visited = new int[total];
        for(int i=0;i<total;i++)
        {
            visited[i] = 0;
        }

        stack<node* >s;

        node*curr = NULL;
        int curr_id;
        temp=adj[key];
        visited[key] = 1;
        s.push(temp);
        while(!s.empty())
        {
            curr=s.top();
            s.pop();
            cout<<" "<<curr->id<<" - "<<curr->data<<" ";
            for(int j=key;j<=total;j++)
            {
                node*ptr = adj[j];
                while(ptr!=NULL)
                {
                    curr_id = ptr->id;
                    if(visited[curr_id] == 0)
                    {
                        s.push(ptr);
                        visited[curr_id] =1;
                    }
                    ptr=ptr->next;
                }
            }
        }
    }
};

int main()
{
    
    graph g;
    g.read();
    g.display();
    int key;
    cout<<"enter source for bfs/dfs: ";
    cin>>key;
    g.dfs(key);
    g.bfs(key);
    return 0;
}