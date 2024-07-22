/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
inline const auto optimize = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        while(root!=NULL){

        if(root->val > p->val && root->val > q->val){
            root = root->left;
        }
        else if(root->val < p->val && root->val < q->val){
            // return lowestCommonAncestor(root->right,p,q);
            root = root->right;
        }
        else{
            return root;
        }
        }
        return root;
    }
};