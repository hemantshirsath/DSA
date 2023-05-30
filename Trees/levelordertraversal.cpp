#include <iostream>
#include <queue>
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
void levelorder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        // cout<<temp->data<<" ";
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    Node *root = NULL;
    root = buildtree(root);
    levelorder(root);

    return 0;
}