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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int,bool>temp;
        TreeNode* root =NULL;

        for(auto i: d){
            temp[i[0]]=1;
        }

        for(auto i:d){
            if(temp.count(i[1])!=0){
                temp[i[1]]=false;
            }
        }
        int rootval;
        for(auto i:temp){
            if(i.second==true){
                rootval = i.first;
            }
        }

        unordered_map<int,TreeNode*>mp;
        for(auto i : d){
            TreeNode* parent = new TreeNode(i[0]);
            TreeNode* child = new TreeNode(i[1]);
            mp[i[0]] = parent;
            mp[i[1]] = child;
        }

        for(auto i:mp){
            cout<<i.first<<"->"<<i.second->val<<" ";
        }

        for(auto i:d){
            TreeNode* parent = mp[i[0]];
            TreeNode* child = mp[i[1]];

            if(i[2]==0){
                parent->right = child;
            }
            else{
                parent->left = child;
            }
        }

        root = mp[rootval];
        return root;
    }
};