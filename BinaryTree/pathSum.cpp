#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};
bool pathSum(Node* root, int target, int s = 0){
    if(!root) return false;
    // static bool ans = false;
    s = s + root->data;
    if( !root->left && !root->right){
        cout<< s<<endl;
        if( s == target){
            return true;
        }
    }
   return  pathSum(root->left, target, s) || pathSum(root->right, target,s);
}

vector<vector<int>> pathsum2(Node* root, int targetSum, int s = 0){
    if(!root) return {};
    static vector<vector<int>> ans;
    static vector<int> v;
    s = s + root->data;

    v.push_back(root->data);
    if( !root->left && !root->right){
        for(int i = 0; i< v.size();i++){
                cout<< v[i] << " ";
            }cout<<endl;
        if( s == targetSum){
            ans.push_back(v);
        }
        v.pop_back();
    }
    pathsum2(root->left, targetSum, s);
    pathsum2(root->right, targetSum, s);

    return ans;
}
int main(){
    struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    // cout<<pathSum(root, 10,0)<<endl;
    vector<vector<int>> val;
    val = pathsum2(root, 7, 0);
    // for(int i = 0; i< val.size();i++){
    //     for(int j = 0; j < val[i].size();j++){
    //         cout<< val[i][j] << " ";
    //     }
    // }
    return 0;
}