//Build tree from inorder and postorder traversal
#include<iostream>
#include "buildtreefromlevelordertraversal.cpp"
using namespace std;
Node *solve(int in[],int post[],int &index,int start,int end,int n){
    if(index<0||start>end){
        return NULL;
    }
    int element=post[index--];
    Node *root=new Node(element);
    int pos;
    for(int i=start;i<=end;i++){
        if(in[i]==element){
            pos=i;
            break;
        }
    }
    root->right=solve(in,post,index,pos+1,end,n);
    root->left=solve(in,post,index,start,pos-1,n);
    return root;
}
void inorder(Node *root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main()
{
    int in[]={4,8,2,5,1,6,3,7};
    int post[]={8,4,5,2,6,7,3,1};
    int n=8;
    int index=n-1;
    Node *ans=solve(in,post,index,0,n-1,n);
    cout<<"Answer is "<<endl;
    inorder(ans);
    return 0;
}