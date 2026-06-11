#include<iostream>
#include<vector>
#include<queue>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



/*void preOrder(TreeNode* root,vector<int>&ans){
    if(!root) return;
    ans.push_back(root->val);
    preOrder(root->left,ans);
    preOrder(root->right,ans);
}*/
/*vector<int> preorderTraversal(TreeNode* root){
    vector<int>ans;
    preOrder(root,ans);
    return ans;
}*/



/*void inOrder(TreeNode* root,vector<int>&ans){
    if(!root) return;
    inOrder(root->left,ans);
    ans.push_back(root->val);
    inOrder(root->right,ans);
}
vector<int> inorderTraversal(TreeNode* root){
    vector<int>ans;
    inOrder(root,ans);
    return ans;
}*/



TreeNode* buildTree() {
    int val;
    cin >> val;

    if (val == -1) return NULL;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal;

        if (leftVal != -1) {
            curr->left = new TreeNode(leftVal);
            q.push(curr->left);
        }

        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new TreeNode(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}



void postOrder(TreeNode* root,vector<int>&ans){
    if(!root) return;
    postOrder(root->left,ans);
    postOrder(root->right,ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root){
    vector<int>ans;
    postOrder(root,ans);
    return ans;
}



int main(){
    TreeNode* root = buildTree();
    vector<int> post;
    postOrder(root, post);
    cout << "Postorder Traversal: ";
    for (int x : post)
        cout << x << " ";
    return 0;
}