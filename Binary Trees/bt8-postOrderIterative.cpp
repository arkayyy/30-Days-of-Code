#include<bits/stdc++.h>
using namespace std;

class BT
{
    public:
        int data;
        BT* left,*right;

        BT(int value)
        {
            this->data=value;
            this->left=this->right=NULL;
        }
};

void postOrderIterative(BT* root,vector<int> &v)
{
    stack<BT*> s;

    s.push(root);

    while(!s.empty())
    {
        BT* t=s.top();
        s.pop();
        v.push_back(t->data);


        if(t->left)
            s.push(t->left);
        if(t->right)
            s.push(t->right);
        
    }

    reverse(v.begin(),v.end());
    
}

int main()
{
    BT* root=new BT(1);
    root->left=new BT(2);
    root->right=new BT(3);
    root->left->left=new BT(4);
    root->left->right=new BT(5);
    vector<int> v;
    postOrderIterative(root,v);

    int i=0;
    for(auto i: v)
    {
        cout<<i<<" ";
    }
    return 0;
}