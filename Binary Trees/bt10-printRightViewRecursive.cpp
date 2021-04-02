#include <bits/stdc++.h>
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

int max_level=0;
void leftViewUtil(BT* root, vector<int> & v, int level)
{
    if(!root)
        return;
    if(level>max_level)
        {
            max_level=level;
            v.push_back(root->data);
        }
    
    leftViewUtil(root->right,v,level+1);
    leftViewUtil(root->left,v,level+1);
    
}

vector<int> leftView(BT* root)
{
    max_level=0;
    vector<int> v;
    leftViewUtil(root,v,1);
    return v;
}

int main()
{
    BT* root=new BT(1);
    root->left=new BT(2);
    root->right=new BT(3);
    root->left->left=new BT(4);
    root->left->right=new BT(5);
    vector<int> v=leftView(root);
    
    int i=0;
    for(auto i:v)
    {
        cout<<i<<" ";

    }
    return 0;
}