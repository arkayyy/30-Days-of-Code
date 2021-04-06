#include<bits/stdc++.h>
using namespace std;

class BT
{
    public:
    int data;
    BT *left,*right;

    BT(int value)
    {
        this->data=value;
        this->left=this->right=NULL;
    }
};

void printLeaves(BT* root, vector<int> &v)
{
    if(!root)
        return;

    printLeaves(root->left,v);
    if(!root->left && !root->right)
    {
        v.push_back(root->data);
    }
    printLeaves(root->right,v);
}

void printLeftBoundary(BT* root,vector<int> &v)
{
    if(!root)
        return;
    
    if(root->left)
    {
        v.push_back(root->data);
        printLeftBoundary(root->left,v);
    }
    else if(root->right)
    {
        v.push_back(root->data);
        printLeftBoundary(root->right,v);
    }
}

void printRightBoundary(BT* root, vector<int> &v)
{
    if(!root)
        return;

    if(root->right)
    {
        printRightBoundary(root->right,v);
        v.push_back(root->data);
    }
    else if(root->left)
    {
        printRightBoundary(root->left,v);
        v.push_back(root->data);
    }
}

int main()
{
    BT* root=new BT(1);
    root->left=new BT(2);
    root->right=new BT(3);
    root->left->left=new BT(4);
    root->left->right=new BT(5);

    vector<int>v;
    v.push_back(root->data);
    printLeftBoundary(root->left,v);
    printLeaves(root->left,v);
    printLeaves(root->right,v);
    printRightBoundary(root->right,v);

    int i;
    for(auto i:v)
        cout<<i<<" ";
    return 0;
}