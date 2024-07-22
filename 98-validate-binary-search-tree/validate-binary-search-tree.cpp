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
    bool solve(TreeNode* root, long long int mini ,long long int maxi){
        if(root==NULL){
            return true;
        }
        // cout<<INT_MAX;
        if(root->val <maxi && root->val > mini){
            bool left = solve(root->left,mini,root->val);
            bool right = solve(root->right,root->val,maxi);

            return left && right;
        }
        else{
            return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) {

        return solve(root,-2147483649,2147483648);
    }
};