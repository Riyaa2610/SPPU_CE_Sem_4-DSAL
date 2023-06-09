// Implementation of a direct access file -Insertion and deletion of a
// record from a Direct Access File.

#include<iostream>
#include<fstream>
using namespace std;

class node{
    public:
    int add;
};

class daf{
    public:
    int empid;
    string name;
    int exp;
    int sal;
    node hTable[10];
    string fname;
    daf(string a)
    {
        for(int i=0;i<10;i++)
        {
            hTable[i].add=-1;
        }
        fname=a;
    }

    void insert()
    {
        cout<<"enter the no of records: ";
        int n;
        cin>>n;
        ofstream fout(fname);
        for(int i=0;i<n;i++)
        {
            cout<<"enter employee id: ";
            cin>>empid;
            cout<<"enter employee name: ";
            cin>>name;
            cout<<"enter employee expreience: ";
            cin>>exp;
            cout<<"enter employee salary: ";
            cin>>sal;

            int l = fout.tellp();  //put pointer tells position of char to be inserted, tellp tells position of put pointer and seekp moves position of put pointer
            int d = empid%10;  //hashindex
            hTable[d].add=l;
            fout<<empid<<" "<<name<<" "<<exp<<" "<<sal<<endl;
            //cout<<l<<" "<<d<<" ";
        }
    }

    void displayrec()
    {
        char buffer[40];
        fstream fin(fname);
        while(!fin.eof())
        {
            fin.getline(buffer,40);
            cout<<buffer<<endl;
        }
        fin.close();
        for(int i=0;i<10;i++)
        {
            cout<<hTable[i].add<<endl;
        }
    }

    void search()
    {
        int id;
        cout<<"enter id to be searched: ";
        cin>>id;
        fstream ifs(fname);
        int index = id%10;
        int l = hTable[index].add;
        ifs.seekg(l,ios::beg);
        char buffer[40];
        while(!ifs.eof())
        {
            ifs.getline(buffer,40);
            cout<<" record found"<<endl;
            cout<<buffer;
        }
    }

    void del_record()
    {
        int id;
        cout<<"enter id to be deleted: ";
        cin>>id;
        fstream ifs(fname);
        int index = id%10;
        int l = hTable[index].add;
        ifs.seekg(l,ios::beg);
        char buffer[40];
        while(!ifs.eof())
        {
            ifs.getline(buffer,40);
            hTable[index].add = -1;
            cout<<"record deleted"<<endl;
        }
        ifs.close();
        remove("abc.txt");
        
    }
};

int main()
{
    daf h("daf.txt");
    h.insert();
    h.search();
    h.displayrec();
    h.del_record();
    h.displayrec();
    return 0;
}