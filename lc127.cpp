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
TreeNode* findNode(TreeNode* root, int t) {
    if(!root)return nullptr;
    if(root->val==t)return root;
    TreeNode* left = findNode(root->left, t);
    if(left)return left;
    return findNode(root->right, t);
}
void mark_parents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&pTrack){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* cur=q.front();
        q.pop();
        if(cur->left){
            pTrack[cur->left]=cur;
            q.push(cur->left);
        }
        if(cur->right){
            pTrack[cur->right]=cur;
            q.push(cur->right);
        }
    }
}
vector<int>distanceK(TreeNode* root, TreeNode* target, int k){
    unordered_map<TreeNode*,TreeNode*>pTrack;
    mark_parents(root,pTrack);
    queue<TreeNode*>q;
    unordered_map<TreeNode*,bool>vis;
    q.push(target);
    vis[target]=true;
    int l=0;
    while(!q.empty()){
        int size=q.size();
        if(l++==k)break;
        for(int i=0;i<size;i++){
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left && !vis[cur->left]){
                vis[cur->left]=true;
                q.push(cur->left);
            }
            if(cur->right && !vis[cur->right]){
                vis[cur->right]=true;
                q.push(cur->right);
            }
            if(pTrack[cur] && !vis[pTrack[cur]]){
                vis[pTrack[cur]]=true;
                q.push(pTrack[cur]);
            }
        }
    }
    vector<int>ans;
    while(!q.empty()){
        TreeNode* c=q.front();
        q.pop();
        ans.push_back(c->val);
    }
    return ans;
}
int main(){
    int n,k,t;
    cin>>n>>k>>t;
    vector<int>v(n);
    for(int&x:v)cin>>x;
    TreeNode* root=buildTree(v);
    TreeNode* tar=findNode(root,t);
    vector<int>ans=distanceK(root,tar,k);
    for(int x:ans)cout<<x<<" ";
    cout<<endl;
}