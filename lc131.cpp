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
string serialize(TreeNode* root){
    if(!root)return"";
    string s="";
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* cur=q.front();
        q.pop();
        if(cur==NULL)s+="null,";
        else s+=to_string(cur->val)+',';
        if(cur!=NULL){
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return s;
}
TreeNode* deserialize(string data){
    if(data.size()==0)return NULL;
    stringstream s(data);
    string s1;
    getline(s,s1,',');
    TreeNode* root=new TreeNode(stoi(s1));
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* cur=q.front();
        q.pop();
        getline(s,s1,',');
        if(s1=="null")cur->left=NULL;
        else{
            TreeNode* leftn=new TreeNode(stoi(s1));
            cur->left=leftn;
            q.push(leftn);
        }
        getline(s,s1,',');
        if(s1=="null")cur->right=NULL;
        else{
            TreeNode* rightn=new TreeNode(stoi(s1));
            cur->right=rightn;
            q.push(rightn);
        }
    }
    return root;
}