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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
         int width =0;
        while(!q.empty()){

            int size = q.size();
             int min_index = q.front().second;
            int first_index,last_index;

            for(int i=0;i<size;i++){
                TreeNode* temp = q.front().first;

                int curr = q.front().second - min_index;
                q.pop();

                if(i==0) first_index = curr;
                if(i==size-1) last_index = curr;

                if(temp->left){
                    q.push({temp->left ,(long long )2*curr +1});
                }
                if(temp->right){
                    q.push({temp->right , (long long )2*curr +2});
                }
            }
            width = max(width , last_index - first_index + 1);
        }
        return width;
    }
};