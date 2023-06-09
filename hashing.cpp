/*Consider telephone book database of N clients. Make use of a hash
table implementation to quickly look up client’s telephone number.
Make use of two collision handling techniques and compare them using
number of comparisons required to find a set of telephone numbers
(Note: Use linear probing with replacement and without replacement)*/

#include<iostream>
#define size 10
using namespace std;


class hashing{
    public:
    long int tel;
    hashing()
    {
        tel = 0;
    }
};

class hashTable{
    public:
    hashing hTable[size];
    hashTable()
    {
        for(int i=0; i<size; i++)
        {
            hTable[i].tel = -1;
        }
    }

    int hashIndex(long int tel)
    {
        return tel % size;
    }

    void insertW0(long int tel)
    {
        int g = hashIndex(tel);
        if(hTable[g].tel == -1)
        {
            hTable[g].tel = tel;
        }
        else
        {
            int n;
            n = (g+1) % size;
            while(hTable[n].tel != -1)
            {
                if(n == g)
                {
                    cout<<"table overflow"<<endl;
                    return;
                }
                n = (n+1) % size;
            }
            hTable[n].tel = tel;
        }
    }

    void insertW(long int k)
    {
        int g = hashIndex(k);
        if(hTable[g].tel == -1)
        {
            hTable[g].tel = k;
        }
        else
        {
            int j = hashIndex(hTable[g].tel);
            if(g!=j)
            {
                long int o = hTable[g].tel;
                hTable[g].tel = k;

                while(hTable[g].tel != -1)
                {
                    g = (g+1) % size;
                }
                hTable[g].tel = o;
            }
            else
            {
                int n;
                n = (g+1) % size;
                while(hTable[n].tel != -1)
                {
                    if(n==g)
                    {
                        cout<<"table overflow"<<endl;
                        return;
                    }
                    n = (n+1) % size;
                }
                hTable[n].tel = k;
            }
        }
    }

    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<i<<" -> "<<hTable[i].tel<<endl;
        }
    }

    bool search(long int tel)
    {
        int g=hashIndex(tel);
        if(hTable[g].tel == tel)
        {
            return true;
        } 
        else
        {
            int n;
            n = (g+1) % size;
            while(hTable[g].tel != tel)
            {
                if(n == g)
                {
                    return false;
                }
                n = (n+1) % size;
            } 
        }
        return true;
    }
};

int main()
    {
        hashTable w;
        hashTable wo;

        int n;
        cout<<"enter total entries: ";
        cin>>n;;
        for(int i=0;i<n;i++)
        {
            long int tel;
            cout<<"enter tel no.: ";
            cin>>tel;
            w.insertW(tel);
            wo.insertW0(tel);
        }
        cout<<"with replacement"<<endl;
        w.display();
        cout<<"without replacement"<<endl;
        wo.display();

        return 0;
    }

   