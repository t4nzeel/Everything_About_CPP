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
int ans,cnt=0;
void inorder(TreeNode* root,int k){
    if(!root)return;
    inorder(root->left,k);
    cnt++;
    if(cnt==k){
        ans=root->val;
        return;
    }
    inorder(root->right,k);
}
int kthSmallest(TreeNode* root, int k){
    inorder(root,k);
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int&x:v)cin>>x;
    TreeNode* root=buildTree(v);
    cout<<kthSmallest(root,k)<<endl;
}