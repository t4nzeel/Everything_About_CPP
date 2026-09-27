#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
TreeNode* findNode(TreeNode* root, int x) {
    if (!root) return NULL;
    if (root->val == x) return root;
    TreeNode* left = findNode(root->left, x);
    if (left) return left;
    return findNode(root->right, x);
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==NULL || root==p || root==q)return root;
    TreeNode* l=lowestCommonAncestor(root->left,p,q);
    TreeNode* r=lowestCommonAncestor(root->right,p,q);
    if(r==NULL)return l;
    else if(l==NULL)return r;
    else return root;
}
int main(){
    int n;
    cin >> n;
    vector<int> level(n);
    for (int i = 0; i < n; i++)cin >> level[i];
    TreeNode* root = buildTree(level);
    int x, y;
    cin >> x >> y;
    TreeNode* p = findNode(root, x);
    TreeNode* q = findNode(root, y);
    TreeNode* ans = lowestCommonAncestor(root, p, q);
    if (ans)cout << ans->val << endl;
    else cout << "Node not found"<<endl;
}