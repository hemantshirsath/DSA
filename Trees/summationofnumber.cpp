#include<iostream>
#include "buildtreefromlevelordertraversal.cpp"
using namespace std;
void solve(Node *root,int temp,int &finalans){
    if(root==NULL){
        return ;
    }
    temp=temp*10+root->data;
    if(root->left==NULL&&root->right==NULL){
        finalans=finalans+temp;
        return;
    }
    solve(root->left,temp,finalans);
    solve(root->right,temp,finalans);
}
int main()
{
    Node *root=Buildtreefromlevelorder();
    levelordertraversal(root);
    int finalans=0;
    int temp=0;
    solve(root,temp,finalans);
    cout<<"total sum is "<<finalans;
    return 0;
}