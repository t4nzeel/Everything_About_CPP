#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* prv=NULL;   //for recursive
void flatten(TreeNode* root){

    //Recursive => (Reverse Pre-Order)

    /*if(root==NULL)return;
    flatten(root->right);
    flatten(root->left);
    root->right=prv;
    root->left=NULL;
    prv=root;*/

    //Stack

    /*stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* cur=st.top(); st.pop();
        if(cur->right)st.push(cur->right);
        if(cur->left)st.push(cur->left);
        if(!st.empty())cur=st.top();
        cur->left=NULL;
    }*/

    //Optimal

    TreeNode* cur=root;
    while(cur!=NULL){
        if(cur->left!=NULL){
            TreeNode* prv=cur->left;
            while(prv->right)prv=prv->right;
            prv->right=cur->right;
            cur->right=cur->left;
            cur->left=NULL;
        }
        cur=cur->right;
    }

}
int main(){}