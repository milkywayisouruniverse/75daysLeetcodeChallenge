/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* p,TreeNode* q,bool &ans){
        if(p==nullptr && q!=nullptr){
            ans&=false;
            return;
        }
        else if(p!=nullptr && q==nullptr){
            ans&=false;
            return;
        }
        else if(p!=nullptr && q!=nullptr && p->val!=q->val){
            ans&=false;
            return ;
        }
        else if(p==nullptr && q==nullptr)return;
        dfs(p->left,q->left,ans);
        dfs(p->right,q->right,ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans=true;
        dfs(p,q,ans);
        return ans;
    }
    void dfs(TreeNode* root,TreeNode* subroot,vector<TreeNode*>&dp){
        if(root==nullptr)return;
        if(root->val==subroot->val){
            dp.push_back(root);
        }
        dfs(root->left,subroot,dp);
        dfs(root->right,subroot,dp);
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        vector<TreeNode*>dp;
        dfs(root,subroot,dp);
        bool  ans=false;
        for(auto it:dp){
            ans=ans||isSameTree(it,subroot);
        }
        return ans;
    }
};