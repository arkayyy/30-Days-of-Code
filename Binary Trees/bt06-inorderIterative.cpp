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

void inOrderIterative(BT* root)
{
    stack<BT*> s;
    BT* curr=root;

    while(!s.empty() || curr!=NULL)
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
 
            curr = curr->right;
        }
    }
}

int main()
{
    BT* root=new BT(1);
    root->left=new BT(2);
    root->right=new BT(3);
    root->left->left=new BT(4);
    root->left->right=new BT(5);
    inOrderIterative(root);
    return 0;
}