#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
void arena(Node* root){
    if(!root) return;
    static int s = 0;
    static int ans = 0;
    s = s + root->data;
    arena(root->left);
    arena(root->right);
    ans = s + root->data;
    cout<<ans<<" ";
    ans = 0;
    // cout<<root->data<<" ";
    // if(root->left) root->data = root->data + root->left->data;
    // if(root->right) root->data = root->data + root->right->data;
    
    
}
void Inorder(Node* root){
    if(!root) return;
    Inorder(root->left);
    cout<< root->data << " ";
    Inorder(root->right);
}
int main(){
    struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    // preorder(root);
    arena(root);
    // preorder(root);
    return 0;
}