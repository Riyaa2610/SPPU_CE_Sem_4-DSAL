/*Implement the Heap sort algorithm using heap data structure with
modularity of programming language.*/

#include<iostream>
#define size 25
using namespace std;

class heapSort{
    public:
    int arr[size];
    int n;
    heapSort()
    {
        cout<<"enter total nodes in bt: ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            arr[i] = 0;
        }
    }

    void input()
    {
        
        for(int i=0;i<n;i++)
        {
            cout<<"enter data from a complete binary tree: ";
            int data;
            cin>>data;
            arr[i] = data;
            cout<<endl;
        }
    }

    void heapify(int arr[], int n,int i)
    {
        int min = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if(left < n && arr[left] < arr[min])
        {
            min = left;
        }
        else if(right < n && arr[right] < arr[min])
        {
            min = right;
        }

        if(i!=min)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            heapify(arr,n,min);
        }
    }

    void heapsort()
    {
        for(int i=n;i>=0;i--)
        {
            heapify(arr,n,i);
        }
        for(int i=n-1;i>=0;i--)
        {
            cout<<arr[0]<<" ";
            int temp=arr[0];
            arr[0]=arr[i];
            arr[i]=temp;
            heapify(arr,i,0);
        }
    }
};

int main()
{
    heapSort h;
    h.input();
    cout<<"the sorted output is: ";
    h.heapsort();

    return 0;
}