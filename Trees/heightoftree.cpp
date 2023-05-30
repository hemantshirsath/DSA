#include<iostream>
#include "buildtreefromlevelordertraversal.cpp"
using namespace std;
int height(Node *root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}
//sum of leaf Nodes
void sum(Node *root,int &ans){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL||root->right!=NULL){
        ans+=root->data;
    }
    sum(root->left,ans);
    sum(root->right,ans);
}

int main()
{
    Node *root=Buildtreefromlevelorder();
    levelordertraversal(root);
    cout<<"Answer of the tree is "<<height(root)<<endl;
    int ans=0;
    sum(root,ans);
    cout<<"answer is "<<ans;
    
    return 0;
}