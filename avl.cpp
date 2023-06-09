#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int value;
    int key;
    int height;
    Node*left;
    Node*right;

    Node()
    {
        value=key=0;
        height=1;
        left=right=NULL;
    }
    Node(int v,int k)
    {
        value=v;
        key=k;
        left=right=NULL;
    }
};

class avl{
    public:
    Node*root=nullptr;

    int height(Node*node)
    {
        if(node==NULL)
        {
            return 0;
        }
        else
        {
            return node->height;
        }
    }

    int balancefactor(Node*node)
    {
        if(node==NULL)
        {
            return 0;
        }
        else
        {
            return(height(node->left) - height(node->right));
        }
    }

    void updateHeight(Node*node)
    {
        node->height = 1+max(height(node->left),height(node->right));
    }

    Node*rotateLeft(Node*node)
    {
        Node*temp = node->right;
        node->right = temp->left;
        temp->left = node;
        updateHeight(node);
        updateHeight(temp);
        return temp;
    }

    Node*rotateRight(Node*node)
    {
        Node*temp = node->left;
        node->left = temp->right;
        temp->right = node;
        updateHeight(node);
        updateHeight(temp);
        return temp;
    }

    Node*rotateLR(Node*node)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    Node*rotateRL(Node*node)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    Node*balance(Node*node)
    {
        if(balancefactor(node) == 2)
        {
            if(balancefactor(node->left) < 0)
            {
                node = rotateLR(node);
            }
            else
            {
                node = rotateRight(node);
            }
        }
        else if(balancefactor(node) == -2)
        {
            if(balancefactor(node->right) < 0)
            {
                node = rotateLeft(node);
            }
            else
            {
                node = rotateRL(node);
            }
        }
        updateHeight(node);
        return node;
    }

    Node*addNode(Node*node,int value,int key)
    {
        if(node==nullptr)
        {
            return new Node(value,key);
        }
        if(value < node->value)
        {
            node->left = addNode(node->left,value,key);
        }
        else if(value > node->value)
        {
            node->right = addNode(node->right,value,key);
        }
        else
        {
            node->value = value;
            return node;
        }
        return balance(node);
    }

    void insert(int value,int key)
    {
        root =  addNode(root,value,key);
    }

    void inorder(Node*node)
    {
        if(node==nullptr)
        {
            return;
        }
        inorder(node->left);
        cout<<node->value<<" ";
        inorder(node->right);
        
    }
    
    void levelTraversal()
    {
        cout<<endl;
        queue<Node* >q;
        Node *p=root;
        q.push(p);
        while(!q.empty())
        {
            p=q.front();
            q.pop();
            cout<<p->value<<" ";
            if(p->left!=nullptr)
            {
                q.push(p->left);
            }
            if(p->right!=nullptr)
            {
                q.push(p->right);
            }
        }
    }
};

int main()
{
    avl a;
    a.insert(100,1);
    a.insert(80,2);
    a.insert(75,3);
    a.inorder(a.root);
    a.levelTraversal();
    return 0;
}