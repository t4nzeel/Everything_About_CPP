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
void build_BST(TreeNode* root,int vl){
    if(root->val >vl){
        if(root->left==nullptr)root->left=new TreeNode(vl);
        else build_BST(root->left,vl);
    }
    else{
        if(root->right==nullptr)root->right=new TreeNode(vl);
        else build_BST(root->right,vl);
    }
}
TreeNode* bstFromPreorder(vector<int>& preorder){
    TreeNode* root=new TreeNode(preorder[0]);
    for(int i=1;i<preorder.size();i++){
        build_BST(root,preorder[i]);
    }
    return root;
}



int idx=0;
TreeNode* build(vector<int>&preorder,int low,int high){
    if(idx==preorder.size())return nullptr;
    int vl=preorder[idx];
    if(vl<low || vl>high)return nullptr;
    TreeNode* root=new TreeNode(vl);
    idx++;
    root->left=build(preorder,low,vl);
    root->right=build(preorder,vl,high);
    return root;
}
TreeNode* bstFromPreorder2(vector<int>& preorder) {
        return build(preorder, INT_MIN, INT_MAX);
    }



vector<int>treeToArray(TreeNode* root) {
    vector<int>ans;
    if(!root)return ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode*cur=q.front();
        q.pop();
        if(cur){
            ans.push_back(cur->val);
            q.push(cur->left);
            q.push(cur->right);
        }
        else ans.push_back(-1);
    }
    while(!ans.empty() && ans.back()==-1)ans.pop_back();
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    TreeNode* root=bstFromPreorder2(v);
    vector<int>ans=treeToArray(root);
    for(int x:ans)cout<<x<<" ";
    cout<<endl;
}