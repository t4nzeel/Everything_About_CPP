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
bool ok(TreeNode*root,ll mx,ll mn){
    if(!root)return true;
    if(root->val<=mn || root->val>=mx)return false;
    return ok(root->left,root->val,mn) && ok(root->right,mx,root->val);
}
bool isValidBST(TreeNode* root){
    return ok(root,LLONG_MAX,LLONG_MIN);
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    TreeNode* root=buildTree(v);
    if(isValidBST(root))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}