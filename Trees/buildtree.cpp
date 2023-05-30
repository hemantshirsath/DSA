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
Node *buildtree(Node *root){
    int data;
    cout<<"Enter data "<<endl;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for left child of "<<root->data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter data for right child of "<<root->data<<endl;
    root->right=buildtree(root->right);
    return root;
}
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    Node *root=NULL;
    root=buildtree(root);
    cout<<"Printing the tree "<<endl;
    inorder(root);
    return 0;
}