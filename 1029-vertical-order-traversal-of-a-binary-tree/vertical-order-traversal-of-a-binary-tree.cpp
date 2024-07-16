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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>mp;

        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){

            int level  = q.front().second.first;
            int hd  = q.front().second.second;
            TreeNode* temp = q.front().first;
            q.pop();

            mp[hd][level].push_back(temp->val);
            sort(mp[hd][level].begin(),mp[hd][level].end());
                if(temp->left){
                    q.push({temp->left,{level+1,hd-1}});
                }
                if(temp->right){
                    q.push({temp->right,{level+1,hd+1}});
                }
            
        }


        vector<vector<int>>ans;
        for(auto i:mp){
            vector<int>temp;
            for(auto j:i.second){
               for(auto k : j.second){
                temp.push_back(k);
               }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};