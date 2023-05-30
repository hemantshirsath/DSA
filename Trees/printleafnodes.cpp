#include<iostream>
#include "buildtreefromlevelordertraversal.cpp"
using namespace std;
void inorder(Node *root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        ans.push_back(root->data);
    }
    inorder(root->left,ans);
    inorder(root->right,ans);
}
int sumofleafNodes(Node *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL&&root->right==NULL){
        return root->data;
    }
    int l=sumofleafNodes(root->left);
    int r=sumofleafNodes(root->right);
    int ans=l+r;
    return ans;
}

int main()
{
    Node *root=Buildtreefromlevelorder();
    levelordertraversal(root);
    vector<int> ans;
    inorder(root,ans);
    cout<<"Leaf Nodes are "<<endl;
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<"Sum of leaf nodes is "<<sumofleafNodes(root)<<endl;
    cout<<"Difference between left and right leaf nodes is ";
    int left=sumofleafNodes(root->left);
    int right(sumofleafNodes(root->right));
    cout<<left-right;

    return 0;
}