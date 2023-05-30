//Recursive inorder postorder traversal tree
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";  
    }
}
void preorder(Node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    Node *root=new Node(1);
    Node *a=new Node(2);
    Node *b=new Node(3);
    Node *c=new Node(4);
    Node *d=new Node(5);
    Node *e=new Node(6);
    Node *f=new Node(7);
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;
    b->right=f;
    inorder(root); 
    cout<<endl;
    postorder(root);
    cout<<endl;
    preorder(root);
    return 0;
}