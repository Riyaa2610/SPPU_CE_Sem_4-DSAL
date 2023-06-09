#include<iostream>
#define max 20
using namespace std;

class obst{
    public:
    int R[max][max];
    int W[max][max];
    int C[max][max];
    int p[max];
    int q[max];
    int keys[max];
    int n;

    void calculating_W_C_R()
    {
        //weight matrix
        for(int i=0; i<=n; i++)
        {
            W[i][i] = q[i];
            for(int j=i+1; j<=n; j++)
            {
                W[i][j] = W[i][j-1] + p[j] + q[j];
            }
        }
        
        //cost matrix
        for(int i=0; i<=n; i++)
        {
            C[i][i] = W[i][i];
        }
        for(int i=0; i<n; i++)
        {
            int j = i+1;
            C[i][j] = C[i][i] + C[j][j] + W[i][j];
            R[i][j] = j;
        }
        for(int i=0; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                int m[n];
                int l=0;
                int r;

                for(int k=i; k<j; k++)
                {
                    int cost = C[i][k] + C[k+1][j];
                    m[l++] = cost;
                }
                int min = m[0];
                for(int k=0; k<(j-i); k++)
                {
                    if(min > m[k])
                    {
                        min = m[k];
                        r = k;
                        R[i][j] = i+k+1;
                    }
                }
                C[i][j] = min + W[i][j];
            }
        }

    }

    void display()
    {
        cout<<"\nthe weight matrix is: "<<endl;
        for(int i=0 ;i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i>j)
                {
                    cout<<"\t";
                }
                else
                {
                    cout<<W[i][j]<<"\t";
                }
            }
            cout<<endl;       
        }

        cout<<"\nthe cost matrix is: "<<endl;
        for(int i=0 ;i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i>j)
                {
                    cout<<"\t";
                }
                else
                {
                    cout<<C[i][j]<<"\t";
                }
            }
            cout<<endl;
        }

        cout<<"\nthe root matrix is: "<<endl;
        for(int i=0 ;i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i>=j)
                {
                    cout<<"\t";
                }
                else
                {
                    cout<<R[i][j]<<"\t";
                }
            }
            cout<<endl;
        }
        
        cout<<"the optimal cost of the bst is: "<<C[0][n]<<endl;
    }

    void input()
    {
        cout<<"enter total no of keys: ";
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cout<<"enter keys: ";
            cin>>keys[i];

            cout<<"enter successful probability: ";
            cin>>p[i];
        }
        for(int i=0; i<=n; i++)
        {
            cout<<"enter unsuccessful probability: ";
            cin>>q[i];
        }
        calculating_W_C_R();
    }
};

int main()
{
    obst o;
    o.input();
    o.display();
    return 0;
}