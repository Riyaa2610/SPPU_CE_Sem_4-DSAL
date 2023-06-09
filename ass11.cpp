// Department maintains a student information. The file contains roll number, name, division and address.
//  Allow user to add, delete information of student. Display information of particular employee. If 
//  record of student does not exist an appropriate message is displayed. If it is, then the system 
//  displays the student details. Use sequential file to main the data.

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

class node{
    public:
    int rollno;
    string name;
    char div;
    string address;

};

class seq{
    public:
    string fname;
    seq(string a)
    {
        fname=a;
    }

    void add_data()
    {
        ofstream ofs(fname);  //ofstream for writing files
        node s;
        int n;
        cout<<"enter the no. of records: "<<endl;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"enter roll no.: ";
            cin>>s.rollno;
            cout<<"enter the name: ";
            cin>>s.name;
            cout<<"enter the division: ";
            cin>>s.div;
            cout<<"enter the address :";
            cin>>s.address;

            ofs<<s.rollno<<" "<<s.name<<" "<<s.div<<" "<<s.address<<endl;
        }
        ofs.close();
    }

    void search_roll(int roll)
    {
        ifstream ifs(fname);  //reading the file
        if(ifs.is_open())
        {
            string line;
            while(getline(ifs,line))
            {
                string arr[4];
                int i=0;
                stringstream input(line);
                while(input.good() && i<4)
                {
                    input>>arr[i];
                    i++;
                }
                if(to_string(roll) == arr[0])
                {
                    cout<<"\nSearch Successfull!";
                    return;
                }
            }
        }
    }

    void del_roll(int roll)
    {
        ifstream ifs(fname);
        ofstream ofs("text.txt");
        if(ifs.is_open())
        {
            string line;
            while(getline(ifs,line))
            {
                string arr[4];
                int i=0;
                stringstream input(line);
                while(input.good() && i<4)
                {
                    input>>arr[i];
                    i++;
                }
                if(to_string(roll) != arr[0])
                {
                    ofs<<line<<endl;
                }
            }
        }
        ifs.close();
        ofs.close();
        remove("riya.txt");
        rename("text.txt","riya.txt");
    }

    void display()
    {
        ifstream ifs(fname);
        string line;
        while(!ifs.eof())
        {
            getline(ifs,line);
            cout<<line<<endl;
        }
    }
};

int main()
{
    seq w("riya.txt");
    w.add_data();
    w.search_roll(83);
    w.display();
    w.del_roll(83);
    w.display();
    return 0;
}