#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct TreeNode {
    ll val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(ll x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTree(vector<ll>& level){
    if (level.empty() || level[0] == -1)
        return NULL;
    TreeNode* root = new TreeNode(level[0]);
    queue<TreeNode*> q;
    q.push(root);
    ll i = 1;
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
ll widthOfBinaryTree(TreeNode* root){
    if(!root)return 0;
    ll ans=0;
    queue<pair<TreeNode*,ll>>q;
    q.push({root,0});
    while(!q.empty()){
        ll sz=q.size();
        ll mn=q.front().second;
        ll f,l;
        for(ll i=0;i<sz;i++){
            ll c=q.front().second-mn;
            TreeNode* node=q.front().first;
            q.pop();
            if(i==0)f=c;
            if(i==sz-1)l=c;
            if(node->left)q.push({node->left,2*c+1});
            if(node->right)q.push({node->right,2*c+2});
        }
        ans=max(ans,l-f+1);
    }
    return ans;
}
ll main(){
    ll n;
    cin >> n;
    vector<ll> level(n);
    for (ll i = 0; i < n; i++)cin >> level[i];
    TreeNode* root = buildTree(level);
    cout<<widthOfBinaryTree(root)<<endl;
}