//....printing the first element from each level traversal


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

vector<int> rightViewIterative(BT* root)
{
    vector<int> v;
    if(!root)
        return {};
    queue<BT*> q;
    q.push(root);

    while(!q.empty())
    {
        int n=q.size();
        for(int i=1;i<=n;i++)
        {   BT* t=q.front();
            q.pop();
            if(i==1)
                v.push_back(t->data);
            // if(i==n)
            //     v.push_back(t->data);


            if(t->right)
                q.push(t->right);
            if(t->left)
                q.push(t->left);

            // if(t->left)
            //     q.push(t->left);
            // if(t->right)
            //     q.push(t->right);
            
        }
    }
    return v;
}

int main()
{
    BT* root=new BT(1);
    root->left=new BT(2);
    root->right=new BT(3);
    root->left->left=new BT(4);
    root->left->right=new BT(5);
    vector<int>v=rightViewIterative(root);
    int i=0;
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    
    return 0;
}