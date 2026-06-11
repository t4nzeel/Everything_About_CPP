#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*TreeNode* insertIntoBST(TreeNode* root, int val){
    if(root==NULL) return new TreeNode(val);
    TreeNode* temp=root;
    TreeNode* prev=NULL;
    while(temp!=NULL){
        prev=temp;
        temp=val<temp->val ? temp->left : temp->right;
    }
    if(prev->val>val) prev->left=new TreeNode(val);
    else prev->right=new TreeNode(val);
    return root;
}*/
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);
    if(val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}
int main(){}