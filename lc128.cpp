#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct TreeNode {
    ll val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(ll x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTree(vector<int>& level){
    if (level.empty() || level[0] == -1)
        return NULL;
    TreeNode* root = new TreeNode(level[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < level.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < level.size() && level[i] != -1) {
            curr->left = new TreeNode(level[i]);
            q.push(curr->left);
        }
        i++;
        if (i < level.size() && level[i] != -1) {
            curr->right = new TreeNode(level[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
int countNodes(TreeNode* root){
    if(root==NULL)return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}
int main(){
    int  n;
    cin>>n;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    TreeNode* root=buildTree(v);
    cout<<countNodes(root)<<endl;
}