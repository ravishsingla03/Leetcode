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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& d) {
        unordered_map<int,pair<TreeNode*,int>>p;
        queue<TreeNode*>q;
        q.push(root);
        p[root->val]={NULL,0};
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left){
                p[temp->left->val]={temp,1};
                q.push(temp->left);
            }
            if(temp->right){
                p[temp->right->val]={temp,2};
                q.push(temp->right);
            }
        }

        vector<TreeNode* >ans;
        if( find(d.begin(),d.end(),root->val)==d.end()){
            ans.push_back(root);
        }
        queue<TreeNode*>q1;
        q1.push(root);
        while(!q1.empty()){
            TreeNode* temp = q1.front();
            q1.pop();


            if(temp->left){
                q1.push(temp->left);
            }
            if(temp->right){
                q1.push(temp->right);
            }
            if(find(d.begin(),d.end(),temp->val)!=d.end()){
                auto temp2 = p[temp->val];
                if(temp2.second==1 && temp2.first!=NULL){
                    temp2.first->left =NULL;
                }else if(temp2.second==2 && temp2.first!=NULL){
                    temp2.first->right =NULL;
                }
                if(temp->left && find(d.begin(),d.end(),temp->left->val)==d.end() ){
                    ans.push_back(temp->left);
                }
                if(temp->right && find(d.begin(),d.end(),temp->right->val)==d.end()){
                    ans.push_back(temp->right);
                }
            }
        }
        return ans;
    }
};