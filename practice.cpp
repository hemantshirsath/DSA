#include<iostream>
#include<queue>
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
Node * buildtree(Node *root){
    int data;
    cout<<"Enter data "<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new Node(data);
    cout<<"Enter data to the left side of "<<root->data<<endl;
    root->left=buildtree(root->left);

    cout<<"Enter data to the right side of the "<<root->data<<endl;
    root->right=buildtree(root->right);
    return root;
}
void inorder(Node *root){
    if(!root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void levelorder(Node *root){
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

        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        }
    }
}
int height(Node *root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}
int main()
{
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1 
    Node *root=NULL;
    root=buildtree(root);
    cout<<"Level order traversal of the tree is "<<endl;
    levelorder(root);
    cout<<"Height of the binary tree is "<<height(root);
    
    return 0;
}