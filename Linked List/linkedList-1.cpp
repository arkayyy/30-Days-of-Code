#include <iostream>
#include <cstdio>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int data){this->data=data;}
};

void print(Node* root){
    while(root!=NULL)
    {
        cout<<root->data<<endl;
        root=root->next;
    }
}
int main(){
    int data;
    cin>>data;
    struct Node* pre=new Node(data);
    struct Node* head=pre;
    while(true)
    {cin>>data;
    struct Node* n=new Node(data);
        if(data==0){pre->next=NULL;break;}
        else{
            
            pre->next=n;
            pre=n;

        }
    }
    print(head);

}

