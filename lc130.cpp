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
/*TreeNode* bT(vector<int>&preorder,int pS,int pE,vector<int>&inorder,int iS,int iE,unordered_map<int,int>&inM){
    if(pS>pE || iS>iE)return NULL;
    TreeNode* root=new TreeNode(preorder[pS]);
    int inRoot=inM[root->val];
    int nleft=inRoot-iS;
    root->left=bT(preorder,pS+1,pS+nleft,inorder,iS,inRoot-1,inM);
    root->right=bT(preorder,pS+1+nleft,pE,inorder,inRoot+1,iE,inM);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    unordered_map<int,int>inM;
    for(int i=0;i<inorder.size();i++)inM[inorder[i]]=i;
    TreeNode* root=bT(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inM);
    return root;
}*/
TreeNode* bT(vector<int>&postorder,int pS,int pE,vector<int>&inorder,int iS,int iE,unordered_map<int,int>&inM){
    if(pS>pE || iS>iE)return NULL;
    TreeNode* root=new TreeNode(postorder[pE]);
    int inRoot=inM[root->val];
    int nleft=inRoot-iS;
    root->left=bT(postorder,pS,pS+nleft-1,inorder,iS,inRoot-1,inM);
    root->right=bT(postorder,pS+nleft,pE-1,inorder,inRoot+1,iE,inM);
    return root;
}
TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder){
    unordered_map<int,int>inM;
    for(int i=0;i<inorder.size();i++)inM[inorder[i]]=i;
    TreeNode* root=bT(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inM);
    return root;
}
int main(){}