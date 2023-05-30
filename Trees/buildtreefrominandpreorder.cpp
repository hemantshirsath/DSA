#include<bits/stdc++.h>
#include "buildtreefromlevelordertraversal.cpp"
using namespace std;
Node *solve(int in[],int pre[],int &index,int start,int end,int n){
    if(index>=n||start>end){
        return NULL;
    }
    int element=pre[index++];
    Node *root=new Node(element);
    int pos;
    for(int i=start;i<=end;i++){
        if(in[i]==element){
            pos=i;
            break;
        }
    }
    root->left=solve(in,pre,index,start,pos-1,n);
    root->right=solve(in,pre,index,pos+1,end,n);
    return root;
}
void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
int main()
{
    int in[]={3,1,4,0,5,2};
    int pre[]={0,1,3,4,2,5};
    int n=6;
    int index=0;
    Node *root=solve(in,pre,index,0,n-1,n);
    cout<<"Answer is "<<endl;
    postorder(root);
    return 0;
}