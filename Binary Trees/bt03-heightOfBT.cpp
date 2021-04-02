#include<bits/stdc++.h>
using namespace std;

struct BT
{
int data;
BT *left,*right;
};

BT* newNode(int value)
{
    BT* n=new BT;
    n->data=value;
    n->left=n->right=NULL;

    return n; 
}

int height(BT* root)
{
    if(root)
        return max(1+height(root->left),1+height(root->right));
    
    return 0;
}

int main()
{
    BT* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);

    cout<<height(root)<<" ";
    return 0;
}

