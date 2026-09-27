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
TreeNode* prv=nullptr;
TreeNode* frst=nullptr;
TreeNode* middle=nullptr;
TreeNode* last=nullptr;
void inorder(TreeNode*root){
    if(!root)return;
    inorder(root->left);
    if(prv && prv->val > root->val){
        if(frst==NULL){
            frst=prv;
            middle=root;
        }
        else last=root;
    }
    prv=root;
    inorder(root->right);
}
void recoverTree(TreeNode* root){
    frst=middle=last=NULL;
    prv=new TreeNode(INT_MIN);
    inorder(root);
    if(frst && last)swap(frst->val,last->val);
    else if(frst && middle)swap(frst->val,middle->val);
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    TreeNode* root=buildTree(v);
    recoverTree(root);
    vector<int>ans=treeToArray(root);
    for(int x:ans)cout<<x<<" ";
    cout<<endl;
}