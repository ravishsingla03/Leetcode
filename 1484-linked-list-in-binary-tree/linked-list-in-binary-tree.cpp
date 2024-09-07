/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(ListNode* head, TreeNode* root){
        if(head==NULL){
            return true;
        }
        if(root==NULL){
            return false;
        }
        if(head->val != root->val){
            return false;
        }
        else{
            return dfs(head->next,root->left) || dfs(head->next,root->right);
        }
    }
    bool solve(ListNode* head, TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(dfs(head,temp)){
                return true;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return solve(head,root);
    }
};