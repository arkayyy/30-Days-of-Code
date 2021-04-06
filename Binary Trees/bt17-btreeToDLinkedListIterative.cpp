//  ITERATIVE SOLUTION  ... 

#include<bits/stdc++.h>
using namespace std;

struct BT
{
    public:
    int data;
    BT* left,*right;

};

BT* newNode(int value)
{
    BT* n=new BT;
    n->data=value;
    n->left=n->right=NULL;
    return n;
}

void inOrder(BT* root,vector<int> &v)
    {
        if(!root)
            return;
        inOrder(root->left,v);
        v.push_back(root->data);
        inOrder(root->right,v);
    }

    BT * bToDLL(BT *root)
    {if(!root)
        return NULL;
        vector<int> v;
        inOrder(root,v);
        BT* top=new BT;
        top->data=v[0];
        top->left=NULL;
        BT* prev=top;
        for(int i=1;i<v.size();i++)
        {BT* t=new BT;
        t->data=v[i];
            t->left=prev;
            prev->right=t;
            prev=t;
        }
        prev->right=NULL;
        
        return top;
    }


int main()
{
    BT* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    // root->left->left=newNode(4);
    //root->left->right=newNode(5);

    BT* top=bToDLL(root);
    BT* curr=top;
    while(curr->right!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->right;
    }
    cout<<curr->data<<"\n";
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->left;
    }

    return 0;

}