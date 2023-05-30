#include<bits/stdc++.h>
#include "buildtreefromlevelordertraversal.cpp"
using namespace std;
void leftview(Node *root,int lvl,vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(lvl==ans.size()){
        ans.push_back(root->data);
    }
    leftview(root->left,lvl+1,ans);
    leftview(root->right,lvl+1,ans);
}
void rightview(Node *root,int lvl,vector<int> &ans){
    if(root==NULL)
    return;

    if(ans.size()==lvl){
        ans.push_back(root->data);
    }
    rightview(root->right,lvl+1,ans);
    rightview(root->left,lvl+1,ans);
}
int main()
{
    Node *root=Buildtreefromlevelorder();
    levelordertraversal(root);
    vector<int> ans;
    rightview(root,0,ans);
    cout<<"right view is "<<endl;
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}