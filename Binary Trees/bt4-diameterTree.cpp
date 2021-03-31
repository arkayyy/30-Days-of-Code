#include<bits/stdc++.h>
using namespace std;

struct BT
{
    int data;
    BT*left,*right;
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
    {
        return max(height(root->left),height(root->right))+1;
    }
    return 0;
}

int diameter(BT* root)
{
    if(!root){return 0;}
    int leftdiam=diameter(root->left);
    int rightdiam=diameter(root->right);

    int lh=height(root->left);
    int rh=height(root->right);

    return max(lh+rh+1,max(leftdiam,rightdiam));
}

int main()
{
    BT* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);

    cout<< diameter(root)<<endl;
    return 0;
}