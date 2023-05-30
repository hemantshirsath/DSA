#include<iostream>
#include<vector>
#include "buildtreefromlevelordertraversal.cpp"
using namespace std;
void lefttraversal(Node *root,vector<int> &ans){
    if((root==NULL||(root->left==NULL&&root->right==NULL))){
        return ;
    }
    ans.push_back(root->data);
    if(root->left){
        lefttraversal(root->left,ans);
    }
    else{
        lefttraversal(root->right,ans);
    }
}
void righttraversal(Node *root,vector<int> &ans){
    if((root==NULL)||(root->left==NULL&&root->right==NULL)){
        return;
    }
    if(root->right){
        righttraversal(root->right,ans);
    }
    else{
        righttraversal(root->left,ans);
    }
    ans.push_back(root->data);
}

void leaftraversal(Node *root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        ans.push_back(root->data);
    }
    leaftraversal(root->left,ans);
    leaftraversal(root->right,ans);
}
int main()
{
   Node * root=Buildtreefromlevelorder();
   levelordertraversal(root);
   vector<int> ans;
   ans.push_back(root->data);
   lefttraversal(root->left,ans);
   leaftraversal(root->left,ans);
   leaftraversal(root->right,ans);
   righttraversal(root->right,ans);
   cout<<"Boundry traversal of tree is "<<endl;
   for(auto x: ans){
    cout<<x<<" ";
   }

    return 0;
}