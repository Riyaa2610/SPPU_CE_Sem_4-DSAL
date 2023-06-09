// Implement all the functions of a dictionary (ADT) using open
// hashing technique: separate chaining using linked list Data: Set of
// (key, value) pairs, Keys are mapped to values, Keys must be
// comparable, and Keys must be unique. Standard Operations: Insert
// (key, value), Find(key), Delete(key)

#include<iostream>
#include<string>
#define size 10
using namespace std;

class node{
    public:
    string key;
    string value;
    node*next;

    node(string k,string v)
    {
        key = k;
        value = v;
        next = NULL;
    }
};

class hashing{
    public:
    node * hTable[size];
    hashing()
    {
        for(int i=0;i<size;i++)
        {
            hTable[i] = NULL;
        }
    }

    int hashIndex(string k)
    {
        int sum = 0;
        for(int i=0;i<k.length();i++)
        {
            sum = sum + k[i];
        }
        return(sum % size);
    }

    void insert(string key,string value)
    {
        int hash_index = hashIndex(value);
        node*curr;
        node*temp = hTable[hash_index];
        node*new_node = new node(key,value);
        if(temp == NULL)
        {
            hTable[hash_index] = new_node;
        }
        else
        {
            curr=temp;
            while(curr->next != NULL)
            {
                curr=curr->next;
            }
            curr->next=new_node;
        }
    }

    void display()
    {
        cout<<"\nNo Chains\n";
        for(int i=0;i<size;i++)
        {
            cout<<" "<<i<<" ";
            node*curr = hTable[i];
            while(curr!=NULL)
            {
                cout<<curr->key<<" : "<<curr->value<<"-->";
                curr=curr->next;
            }
            cout<<endl;
        }
    }

    void del(string value)
    {
        int loc=hashIndex(value);
        node*temp = hTable[loc];
        node*curr=temp;
        node*prev=NULL;
        bool flag = false;
        if(temp==NULL)
        {
            cout<<"element is not present"<<endl;
        }
        if(curr->value==value)
        {
            hTable[loc] = curr->next;
            delete curr;
            cout<<"element deleted";
        }
        else
        {
            while(curr!=NULL)
            {
                if(curr->value==value)
                {
                    flag = true;
                    break;
                }
                prev=curr;
                curr=curr->next;
            }
            if(flag)
            {
                prev->next = curr->next;
                delete curr;
                cout<<"element deleted";
            }
            else
            {
                cout<<"element not found";
            }
        }
    }

    void search(string value)
    {
        int loc=hashIndex(value);
        node*temp=hTable[loc];
        node*curr=temp;
        bool flag = false;
        if(temp == NULL)
        {
            cout<<"not found"<<endl;
            return;
        }
        else
        {
            //curr=temp;
            if(curr->value==value)
            {
                flag =true;
                cout<<"element found"<<endl;
            }
            else
            {
                curr=curr->next;
            }
        }
        if(flag==false)
        {
            cout<<"element not found";
        }
    }
};

int main()
{
    hashing h;
    cout<<"total node: ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string value,key;
        cout<<"enter key and value pair";
        cin>>key>>value;
        h.insert(key,value);
    }
    h.display();
     for(int i=0;i<n;i++)
    {
        string value,key;
        cout<<"\nenter value to be searched and deleted :";
        cin>>value;
        h.search(value);
        h.del(value);
    }
    return 0;
}