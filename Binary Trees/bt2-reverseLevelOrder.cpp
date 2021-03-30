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

vector<int> reverseLevelOrder(BT* root)
{
    queue<BT*> q;
    vector<int> output;
    stack<int> s;

    q.push(root);
    while(!q.empty())
    {
        BT* t=q.front();
        q.pop();
        s.push(t->data);
        //output.push_back(t->data);
        if(t->right){q.push(t->right);}
        if(t->left){q.push(t->left); }
        

    }

    while(!s.empty())
    {
        output.push_back(s.top());
        s.pop();
    }
    
    

    //reverse(output.begin(),output.end());
    return output;
}


int main()
{
    BT* root=new BT(1);
    root->left=new BT(2);
    root->right=new BT(3);
    root->left->left=new BT(4);
    root->left->right=new BT(5);
    vector<int> v= reverseLevelOrder(root);
int i=0;
    for(auto i: v)
    {cout<<i<<" ";}
    return 0;
}