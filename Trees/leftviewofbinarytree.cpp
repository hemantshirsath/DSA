#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include "buildtreefromlevelordertraversal.cpp"
using namespace std;
vector<int> leftview(Node *root){
    vector<int> finalans;
    if(root==NULL){
        return finalans;
    }
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        if(temp==NULL){
            if(!ans.empty()){
                finalans.push_back(ans[0]);
                ans.clear();
            }
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            ans.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return finalans;
}
vector<int> rightview(Node *root){
    vector<int> finalans;
    if(root==NULL){
        return finalans;
    }
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        if(temp==NULL){
            if(!ans.empty()){
                int ind=ans.size()-1;
                finalans.push_back(ans[ind]);
                ans.clear();
            }
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            ans.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return finalans;
}
vector<int> levelwise(Node *root){
    map<int,map<int,vector<int>>> nodes;
    queue<pair<Node*,pair<int,int>>> q;
    vector<int> ans;
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<Node *,pair<int,int>> temp=q.front();
        q.pop();
        Node *frontnode=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;
        nodes[hd][lvl].push_back(frontnode->data);
        if(frontnode->left){
            q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
        }
         if(frontnode->right){
            q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
        }
    }
    for(auto i:nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}
vector<int> topview(Node *root){
    map<int,int>  topnode; //here mapping between horizontal distance and root->data 
    queue<pair<Node *,int>> q; //queue storing the data and its horizontal distance mapping
    vector<int> ans; //vector to store the array 
    if(root==NULL){ //base case
        return ans;
    }
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node *,int> temp=q.front();
        q.pop();
        Node *frontnode=temp.first;
        int hd=temp.second;
        if(topnode.find(hd)==topnode.end()){
            topnode[hd]=frontnode->data;
        }
        if(frontnode->left){
            q.push(make_pair(frontnode->left,hd-1));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,hd+1));
        }
    }
    for(auto it:topnode){
        ans.push_back(it.second);
    }
    return ans;
}
vector<int> bottomview(Node *root){
    map<int,int>  topnode; //here mapping between horizontal distance and root->data 
    queue<pair<Node *,int>> q; //queue storing the data and its horizontal distance mapping
    vector<int> ans; //vector to store the array 
    if(root==NULL){ //base case
        return ans;
    }
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node *,int> temp=q.front();
        q.pop();
        Node *frontnode=temp.first;
        int hd=temp.second;
            topnode[hd]=frontnode->data;
       
        if(frontnode->left){
            q.push(make_pair(frontnode->left,hd-1));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,hd+1));
        }
    }
    for(auto it:topnode){
        ans.push_back(it.second);
    }
    return ans;
}
int main()
{
    Node *root=Buildtreefromlevelorder();
    levelordertraversal(root);

    vector<int> ans=bottomview(root);
    cout<<"Bottom view of binary tree is "<<endl;
    for(auto x:ans){
        cout<<x<<" ";
    }













    // vector<int> ans=leftview(root);
    // cout<<"Left view of the tree is "<<endl;
    // for(auto x:ans){
    //     cout<<x<<" ";
    // }
    // vector<int> ans2=rightview(root);
    // cout<<"Right view of the tree is "<<endl;
    // for(auto x: ans2){
    //     cout<<x<<" ";
    // }
    // vector<int> ans3=levelwise(root); //this is levelwise 
    // cout<<"Topview of the tree is "<<endl;
    // for(auto x:ans3){
    //     cout<<x<<" ";
    // }


    return 0;
}