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
    void solve(TreeNode* root , unordered_map<int,int>&mp){
        if(root==NULL){
            return;
        }
        solve(root->left,mp);
        mp[root->val]++;
        solve(root->right,mp);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int>v;
        unordered_map<int,int>mp;
        solve(root,mp);
        int max = 0;
        for(auto i:mp){
            if(i.second>max){
                max =i.second;
            }
        }
        for(auto i:mp){
            if(i.second ==max){
                v.push_back(i.first);
            }
        }
        return v;
    }
};