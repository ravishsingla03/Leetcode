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
    bool solve(TreeNode* left , TreeNode* right){
        if(!left && !right){
            return true;
        }

        if(!left && right){
            return false;
        }
        if(left && !right){
            return false;
        }
        if(left->val!=right->val){
            return false;
        }

        bool leftans = solve(left->left,right->right);
        bool rightans = solve(left->right,right->left);
        return leftans && rightans;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        return solve(root->left , root->right);
    }
};