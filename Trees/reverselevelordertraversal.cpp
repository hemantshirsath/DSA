#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildtree(Node *root)
{
    int data;
    cout << "Enter data " << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter left data of " << root->data << endl;
    root->left = buildtree(root->left);

    cout << "Enter right data of " << root->data << endl;
    root->right = buildtree(root->right);
    return root;
}
void reverselevelorder(Node *root){
    queue<Node *> q;
    stack<int> st;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp=q.front();
        // st.push(temp->data);
        q.pop();
        if(temp==NULL){
            st.push(INT_MIN);
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            st.push(temp->data);
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
      
        }
    }
    while(!st.empty()){
        if(st.top()==INT_MIN)
        cout<<endl;
        else
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main()
{
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    Node *root = NULL;
    root = buildtree(root);
    reverselevelorder(root);

    return 0;
}