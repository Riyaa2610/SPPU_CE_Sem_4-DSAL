// Beginning with an empty binary tree, Construct binary tree by inserting
// the values in the order given. After constructing a binary tree perform
// following operations on it-
//  Perform in order / pre order and post order traversal
//  Change a tree so that the roles of the left and right pointers are
// swapped at every node
//  Find the height of tree
//  Copy this tree to another [operator=]
//  Count number of leaves, number of internal nodes.
//  Erase all nodes in a binary tree.
// (implement both recursive and non-recursive methods)

#include<iostream>
#include<queue>
#include<stack>

static int count;
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d)
    {
        right=left=NULL;
        data=d;
    }
};

class bt{
    public:
    node*insert(node*root)
    {
        cout<<"Enter the data: ";
        int data;
        cin>>data;
        root=new node(data);
        if(data==-1)
        {
            return NULL;
        }
        cout<<"Enter the data to the left of "<<data<<endl;
        root->left=insert(root->left);
        cout<<"Enter the data to the right of "<<data<<endl;
        root->right=insert(root->right);
    }

    void levelorder(node*root)
    {
        //cout<<"level order traversal";
        queue<node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            node*p=q.front();
            q.pop();
            if(p==NULL)
            {
                cout<<endl;
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                cout<<p->data;
                if(p->left)
                {
                    q.push(p->left);
                }
                if(p->right)
                {
                    q.push(p->right);
                }
            }
        }
    }

    void swap(node*root)
    {
        //cout<<"swapping of nodes";
        if(root==NULL)
        {
            return;
        }
        else
        {
            swap(root->left);
            swap(root->right);
            node*t;
            t=root->left;
            root->left=root->right;
            root->right=t;
        }
    }

    void del(node*root)
    {
        //cout<<"delete the entire tree";
        if(root==NULL)
        {
            return;
        }
        else
        {
            del(root->left);
            del(root->right);
            delete root;
        }
    }

    void internal(node*root)
    {
        //cout<<"internal nodes are:";
        if(root==NULL)
        {
            return;
        }
        else
        {
            internal(root->left);
            internal(root->right);
            if(root->left==NULL && root->right==NULL)
            {
                cout<<root->data<<endl;
            }
        }
    }

    void inorder(node*root)
    {
        //cout<<"inorder is:";
        stack<node*>st;
        node*c=root;
        while(c!=NULL && !st.empty())
        {
            while(c!=NULL)
            {
                st.push(c);
                c=c->left;
            }
            c=st.top();
            st.pop();
            cout<<c->data;
            c=c->right;
        }
        cout<<endl;
    }

    void preorder(node*root)
    {
        //cout<<"preorder is:";
        if(root==NULL)
        {
            return;
        }
        stack<node*>st;
        st.push(root);
        while(!st.empty())
        {
            node*c=st.top();
            st.pop();
            cout<<c->data;
            if(c->right)
            {
                st.push(c->right);
            }
            if(c->left)
            {
                st.push(c->left);
            }
        }
    }

    int height(node*root)
    {
        //cout<<"height:";
        if(root==NULL)
        {
            return 0;
        }
        else
        {
            if(height(root->left) > height(root->right))
            {
                return(1+height(root->left));
            }
            else
            {
                return(1+height(root->right));
            }
        }
    }
};

int main()
{
    bt t;
    node*root;
    root=t.insert(root);
    t.levelorder(root);
    cout<<t.height(root);
    t.inorder(root);
    t.preorder(root);
    t.internal(root);
    t.swap(root);
    t.del(root);

    return 0;
}