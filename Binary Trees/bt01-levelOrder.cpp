#include <bits/stdc++.h>
using namespace std;

class BT
{   public:
    int data;
    BT* left,*right;

    BT(int value)
    {
        this->data=value;
        this->left=this->right=NULL;
    }
};

void levelOrder(BT* root)
{
    queue<BT*> q;
    vector<int> output;

    q.push(root);

    while(!q.empty())
    {   BT* t=q.front();
        q.pop();
        cout<<t->data<<" ";
        

        if(t->left){q.push(t->left);}
        if(t->right){q.push(t->right);}
    }

}

int main()
{
    BT* root=new BT(1);
    root->left=new BT(3);
    root->right=new BT(2);
    root->left->left=new BT(4);
    root->left->right=new BT(5);
    


    levelOrder(root);

    return 0;
}