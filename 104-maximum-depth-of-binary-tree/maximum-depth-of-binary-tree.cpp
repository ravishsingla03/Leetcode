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
    void solve(TreeNode* root,int ans,int &maxans){
        if(root==NULL){
            return ;

        }
        if(!root->left && root->right==NULL){
            maxans =max(ans,maxans);
            return ;
        }

        solve(root->left,ans+1,maxans);
        solve(root->right,ans+1, maxans);
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int maxans=1;
        solve(root,1,maxans);
        return maxans;
    }
};