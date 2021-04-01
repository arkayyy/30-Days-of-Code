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

void preOrder(BT* root)
{
    stack<BT*> s;

    s.push(root);

    while(!s.empty())
    {
        BT* t=s.top();
        s.pop();
        cout<<t->data<<" ";

        if(t->right)
            s.push(t->right);
        if(t->left)
            s.push(t->left);
    }
    
}

int main()
{
    BT* root=new BT(1);
    root->left=new BT(2);
    root->right=new BT(3);
    root->left->left=new BT(4);
    root->left->right=new BT(5);
    preOrder(root);
    return 0;
}