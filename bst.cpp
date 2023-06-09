/*Beginning with an empty binary search tree. Construct the binary
search tree by inserting the values in given order. After constructing
binary search tree perform following operations 
1) Insert a new node 
2) Find numbers of node in longest path 
3) Minimum and maximum data value found in tree 
4) Change a tree so that the roles of the left and right pointers are swapped at every node 
5) Search an element*/

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
};

class bst{
    public:
    node*root;
    bst()
    {
        root = NULL;
    }
    void insert()
    {
        node *curr,*temp;
        cout<<"enter data: ";
        curr = new node;
        cin>>curr->data;
        curr->left=curr->right = NULL;
        if(root == NULL)
        {
            root=curr;
        }
        else
        {
            temp = root;
            while(1)
            {
                if(curr->data <= temp->data)
                {
                    if(temp->left == NULL)
                    {
                        temp->left = curr;
                        break;
                    }
                    else
                    {
                        temp=temp->left;
                    }
                }
                else
                {
                    if(temp->right == NULL)
                    {
                        temp->right = curr;
                        break;
                    }
                    else
                    {
                        temp=temp->right;
                    }
                }
            }
        }
    }

    void minimum()
    {
        node*temp;
        int min;
        temp =root;
        while(temp->left!=NULL)
        {
            min = temp->data;
            temp=temp->left;
            if(temp->data < min)
            {
                min = temp->data;
            }
            else
            {
                temp = temp->left;
            }
        }
        cout<<"\nminimum value in the bst is: "<<min;
    }

    void maximum()
    {
        node*temp;
        int max;
        temp=root;
        while(temp->right!=NULL)
        {
            max =temp->data;
            temp=temp->right;
            if(temp->data > max)
            {
                max = temp->data;
            }
            else
            {
                temp=temp->right;
            }
        }
        cout<<"\nmaximum value in bst is: "<<max;
    }

    int height(node*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        else
        {
            if(height(root->left) > height(root->right))
            {
                return(1 + height(root->left));
            } 
            else
            {
                return(1+ height(root->right));
            }
        }
    }

    void inorder(node*root)  //left->root->right
    {
        if(root!=NULL)
        {
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
            cout<<endl;
        }
        
    }

    void preorder(node*root)  //root->left->right
    {
        if(root!=NULL)
        {
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
            cout<<endl;
        }
        
    }

    void postorder(node*root)  //left->right->root
    {
        if(root!=NULL)
        {
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
            cout<<endl;
        }
    }

    void search(int key)
    {
        node*curr;
        curr=root;
        while(curr!=NULL)
        {
            if(curr->data == key)
            {
                cout<<"found";
                break;
            }
            else
            {
                if(key < curr->data)
                {
                    curr=curr->left;
                }
                else
                {
                    curr=curr->right;
                }
            }
        }
        if(curr==NULL)
        {
            cout<<"not found";
        }
    }

    void swap(node*root)
    {
        node*curr;
        curr = root;
        if(root == NULL)
        {
            return;
        }
        else
        {
            swap(curr->left);
            swap(curr->right);
            node*temp;
            temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
        }
    }

    node*del(node*temp,int val)
    {
        if(temp == NULL)
        {
            return NULL;
        }
        if(val >temp->data)
        {
            temp->right = del(temp->right,val);
        }
        else if(val < temp->data)
        {
            temp->left = del(temp->left,val);
        }
        else
        {
            if(temp->left == NULL && temp->right == NULL)
            {
                return NULL;
            }
            else if(temp->left == NULL)
            {
                node*t = temp->right;
                delete temp;
                return t;
            }
            else if(temp->left == NULL)
            {
                node*z = temp->left;
                delete temp;
                return z;
            }
        }
    }
};

int main()
{
    bst b;
    int key;
    int value;
    int n;
    cout<<"enter total nodes in bst: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        b.insert();
    }

    b.inorder(b.root);
    b.preorder(b.root);
    b.postorder(b.root);
    cout<<"\nenter key: ";
    cin>>key;
    b.search(key);
    b.minimum();
    b.maximum();
    b.swap(b.root);
    cout<<"\nenter value to be deleted";
    cin>>value;
    b.del(b.root,value);
    b.inorder(b.root);
    
}