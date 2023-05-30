//Build tree from level order traversal of the tree 
#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void levelordertraversal(Node *root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
Node * Buildtreefromlevelorder(){
    int data;
    cout<<"Enter root data "<<endl;
    cin>>data;
    Node *root=new Node(data);
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        int l;
        cout<<"Enter left data of "<<temp->data<<":"<<endl;
        cin>>l;
        if(l==-1){
            temp->left=NULL;
        }
        else{
             Node *a=new Node(l);
        temp->left=a;
        q.push(a);
        }
       
        int r;
        cout<<"Enter right data of "<<temp->data<<":"<<endl;
        cin>>r;
        if(r==-1){
            temp->right=NULL;
        }
        else{
        Node *b=new Node(r);
        temp->right=b;
        q.push(b);
        }

    }
    return root;
}
// void inorder(Node *root){
//     if(root!=NULL){
//         inorder(root->left);
//         cout<<root->data<<" ";
//         inorder(root->right);
//     }
// }
// int main()
// {
//     Node *root=Buildtreefromlevelorder();
//     cout<<"Level Order traversal of tree is "<<endl;
//     levelordertraversal(root);
//     cout<<"inorder traversal of tree is "<<endl;
//     inorder(root);
//     return 0;
// }