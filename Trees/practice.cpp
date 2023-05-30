#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node *buildtreefromlevelordertraversal(){
    queue<Node *> q;
    int data;
    cout<<"Enter root data"<<endl;
    cin>>data;
    Node *root=new Node(data);
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        int l;
        cout<<"Enter left data of "<<temp->data<<" Node "<<endl;
        cin>>l;
        if(l==-1){
            temp->left=NULL;
        }
        else{
            Node *a=new Node(l);
            temp->left=a;
            q.push(a);
        }
        int r;
        cout<<"Enter right data of "<<temp->data<<" Node "<<endl;
        cin>>r;
        if(r==-1){
            temp->right=NULL;
        }
        else{
            Node *b=new Node(r);
            temp->right=b;
            q.push(b);
        }
    }
    return root;
}
void levelordertraversal(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
}
int main()
{
    Node *root=buildtreefromlevelordertraversal();
    levelordertraversal(root);
    return 0;
}