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
struct info{
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
};
int ans=0;
info dfs(TreeNode* root){
    if(!root)return{true,INT_MAX,INT_MIN,0};
    info left=dfs(root->left);
    info right=dfs(root->right);
    if(left.isBST && right.isBST &&
        root->val > left.maxVal && root->val <right.minVal){
            int curSum=right.sum+left.sum+root->val;
            ans=max(ans,curSum);
            return{true,
                min(root->val,left.minVal),
                max(root->val,right.maxVal),
                curSum};
    }
    return{false,INT_MIN,INT_MAX,0};
}
int maxSumBST(TreeNode* root){
    dfs(root);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &X:v)cin>>X;
    TreeNode* root=buildTree(v);
    cout<<maxSumBST(root)<<endl;
}