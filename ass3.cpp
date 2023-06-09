#include <iostream>
using namespace std;
class node
{
    int key;
    bool rbit, lbit;
    node *left, *right;

public:
    node()
    {
        rbit = lbit = false;
        left = right = NULL;
        key = 0;
    }
    friend class tbt;
};
class tbt
{
    node *head;

public:
node *root;
    tbt()
    {
        head = root = NULL;
        head = new node;
        head->key = -99;
        head->left = head->right = head;
        head->rbit = 1;
        head->lbit = 0;
    }
    void create()
    {
        int h;
        cout << "Enter the number of elements you want to insert" << endl;
        cin >> h;
        for (int i = 0; i < h; i++)
        {
            int x;
            cout << "Enter the elements you want to enter" << endl;
            cin >> x;
            this->insert(x);
        }
    }
    void insert(int j)
    {
        if (root == NULL)
        {
            root = new node;
            root->key = j;
            root->lbit = head->lbit;
            root->rbit = 0;
            root->left = root->right = head;
            head->lbit = 1;
            head->left = root;
            return;
        }
        else
        {
            node *temp, *ptr;
            temp = new node;
            temp->key = j;
            ptr = root;
            while (1)
            {
                if (temp->key < ptr->key)
                {
                    if (ptr->lbit != 0)
                    {
                        ptr = ptr->left;
                    }
                    else
                    {
                        temp->rbit = 0;
                        temp->lbit = ptr->lbit;
                        temp->left = ptr->left;
                        temp->right = ptr;
                        ptr->lbit = 1;
                        ptr->left = temp;
                        return;
                    }
                }
                else
                {
                    if (ptr->rbit != 0)
                    {
                        ptr = ptr->right;
                    }
                    else
                    {
                        temp->lbit = 0;
                        temp->rbit = ptr->rbit;
                        temp->right = ptr->right;
                        temp->left = ptr;
                        ptr->rbit = 1;
                        ptr->right = temp;
                        return;
                    }
                }
            }
        }
    }
    node *inordersucc(node *c)
    {
        if (c->rbit != 0)
        {
            c = c->right;
        }
        else
            return c->right;
        while (c->lbit != 0)
        {
            c = c->left;
        }
        return c;
    }
    void inorder()
    {
        node *u = root;
        while (u->lbit != 0)
        {
            u = u->left;
        }
        while (u != head)
        {
            cout << u->key << endl;
            u = inordersucc(u);
        }
    }
    node *delth(node *root, int h)
    {
        node *ptr = root, *par = NULL;
        int found = 0;
        while (ptr != NULL)
        {
            if (ptr->key == h)
            {
                found = 1;
                break;
            }
            par=ptr;
            if(h<ptr->key)
            {
                if(ptr->lbit!=0) ptr=ptr->left;
                else break;
            }
            else if(h>ptr->key)
            {
                if(ptr->rbit!=0) ptr=ptr->right;
                else break;
            }
        }
        if(found ==0)cout<<"Element not present"<<endl;
        else if(ptr->lbit==0 && ptr->rbit==0) root=caseA(par,ptr,root);
        else if(ptr->lbit==1 && ptr->rbit==0) root=caseB(par,ptr,root);
        else if(ptr->lbit==0 && ptr->rbit==1) root=caseB(par,ptr,root);
        else root=caseC(par,ptr,root);
        return root;
    }
    node *caseA(node *par,node *ptr,node *root)
    {
        if(par==NULL)
        {
            root=NULL;
        }
        else if(par->left==ptr)
        {
            par->left=ptr->left;
            par->lbit=0;
        }
        else
        {
            par->right=ptr->right;
            par->rbit=0;
        }
        free(ptr);
        return root;
    }
    node *inorderpre(node *c)
    {
        if(c->lbit==1)c=c->left;
        else return c->left;
        while(c->rbit!=0)c=c->right;
        return c;
    }
    node *caseB(node *par,node *ptr,node *root)
    {
        node *child;
        if(ptr->lbit==1)child=ptr->left;
        else child =ptr->right;
        if(ptr=par->left)par->left=child;
        else par->right=child;
        node *p=inorderpre(ptr);
        node *s=inordersucc(ptr);
        if(ptr->lbit)p->right=s;
        else s->left=p;
        return root;
    }
    node *caseC(node *par,node *ptr,node *root)
    {
        node *parsuc=ptr;
        node *suc=ptr->right;
        while(suc->lbit==1)
        {
            parsuc=suc;
            suc=suc->left;
        }  
        ptr->key=suc->key;
        if(suc->lbit==0 && suc->rbit==0)root=caseA(parsuc,suc,root);
        else root=caseB(parsuc,suc,root);
        return root;
    }
};
int main()
{
    tbt f;
    f.create();
    f.delth(f.root,3);
    f.delth(f.root,4);
    f.inorder();

}