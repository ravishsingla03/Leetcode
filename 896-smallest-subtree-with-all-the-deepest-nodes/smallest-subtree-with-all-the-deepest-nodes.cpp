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
    vector<TreeNode*> solve(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*>ls;
        while(!q.empty()){
            int size = q.size();
            ls.clear();
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                ls.push_back(temp);
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                   q.push(temp->right);
                }
            }
        }
        return ls;
    }

    TreeNode* solve(vector<TreeNode*>&leaf,TreeNode* &root){
        if(root==NULL){
            return root;
        }
        for(int i =0;i<leaf.size();i++){
            if(root==leaf[i]){
                return root;
            }
        }

        TreeNode* left = solve(leaf,root->left);
        TreeNode* right = solve(leaf,root->right);
        if(left==NULL){
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else{
            return root;
        }
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
         vector<TreeNode*> leaf = solve(root);   
       return solve(leaf,root);
    }
};