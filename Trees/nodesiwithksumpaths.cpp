//Count the nodes with the k sum path 
#include<iostream>
#include "buildtreefromlevelordertraversal.cpp"
using namespace std;
void ksum(Node *root,int k,int &count,vector<int> path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    ksum(root->left,k,count,path);
    ksum(root->right,k,count,path);
    int size=path.size();
    int sum=0;
    for(int i=size-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){
            count++;
        }
    }
    path.pop_back();
}
int main()
{
    Node *root=Buildtreefromlevelorder();
    levelordertraversal(root);
    int count=0;
    vector<int> path;
    ksum(root,3,count,path);
    cout<<"Total count of path are "<<count;

    return 0;
}