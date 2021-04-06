#include<bits/stdc++.h>
using namespace std;

class BT
{
    public:
    int data;
    BT* left, *right;

    BT(int value)
    {
        this->data=value;
        this->left=this->right=NULL;
    }
};

void diagTraversalUtil(BT* root, int sd, map<int,vector<int>>&m)
{
    if(!root)
        return;

    m[sd].push_back(root->data);
    diagTraversalUtil(root->right,sd,m);
    diagTraversalUtil(root->left,sd+1,m);

}

vector<int> diagTraversal(BT* root)
{vector<int>v;
    if(!root)
        return {};

    map<int,vector<int>> m;
    diagTraversalUtil(root, 0,m);

    for(auto i=m.begin();i!=m.end();i++)
    {
        v.insert(v.end(),i->second.begin(),i->second.end());
    }
    return v;

}

int main()
{
    BT* root= new BT(1);
    root->left=new BT(2);
    root->right=new BT(3);
    root->left->left=new BT(4);
    root->left->right=new BT(5);

    vector<int> v=diagTraversal(root);
    int i=0;
    for(auto i:v)
        cout<<i<<" ";
    return 0;
}