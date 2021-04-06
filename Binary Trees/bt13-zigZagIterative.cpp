#include <bits/stdc++.h>
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

vector<int> zigZagTraversalIterative(BT* root)
{
    vector<int> v;
    queue<BT*> q;
    q.push(root);
    int c=2;
    while(!q.empty())
    {vector<int> temp;
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            BT* t=q.front();
            q.pop();
            temp.push_back(t->data);
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }

        if(c%2==0)
            v.insert(v.end(),temp.begin(),temp.end());
        else
        {reverse(temp.begin(),temp.end());
            v.insert(v.end(),temp.begin(),temp.end());
        }
         c++;   
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
    vector<int> v=zigZagTraversalIterative(root);
    int i=0;
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    return 0;
}