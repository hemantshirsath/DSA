#include<iostream>
#include<queue>
#include "buildtreefromlevelordertraversal.cpp"
using namespace std;
vector<int>  zigzagtraversal(Node *root){
    queue<Node *> q;
    vector<int> result;
    if(root==NULL){
        return result;
    }
    bool lefttoright=true;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            Node *temp=q.front();
            q.pop();
            int index=lefttoright?i:n-i-1;
            ans[index]=temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        lefttoright=!lefttoright;
        for(auto x:ans){
            result.push_back(x);
        }
    }
        return result;

}
int main()
{
    Node *root=Buildtreefromlevelorder();
    levelordertraversal(root);
    vector<int> ans=zigzagtraversal(root);
    cout<<"Zigzag traversal of the tree is "<<endl;
    for(auto x: ans){
        cout<<x<<" ";
    }

    return 0;
}