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
void inorder(TreeNode*root,vector<int>&v){
    if(!root)return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
bool findTarget(TreeNode* root, int k){
    vector<int>v;
    inorder(root,v);
    int l=0,r=v.size()-1;
    while(l<r){
        int s=v[l]+v[r];
        if(s==k)return true;
        else if(s>k)r--;
        else l++;
    }
    return false;
}

unordered_set<int>seen;
bool dfs(TreeNode* root,int k){
    if(!root)return false;
    if(seen.count(k-root->val))return true;
    seen.insert(root->val);
    return dfs(root->left,k) || dfs(root->right,k);
}
bool findTarget2(TreeNode* root, int k){
    return dfs(root,k);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int&x:v)cin>>x;
    TreeNode* root=buildTree(v);
    if(findTarget2(root,k))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}