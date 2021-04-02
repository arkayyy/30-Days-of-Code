#include <bits/stdc++.h>
using namespace std;

struct BT
{
    int data;
    BT *left, *right;
};

BT *newNode(int value)
{
    BT *n = new BT;
    n->data = value;
    n->left = n->right = NULL;
    return n;
}
vector<int> mirrorPrint(BT *root, vector<int> &out)
{

    if (root)
    {
    out=mirrorPrint(root->right,out);
    //cout << root->data << " ";
    out.push_back(root->data);
    out=mirrorPrint(root->left,out);}

    return out;
}

int main()
{
    BT *root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(8);
    root->left->left = newNode(12);
    root->right->right = newNode(9);

    vector<int> v;
    mirrorPrint(root,v);
    for(auto i:v)
    {cout<<i<<" ";}
    return 0;
}
