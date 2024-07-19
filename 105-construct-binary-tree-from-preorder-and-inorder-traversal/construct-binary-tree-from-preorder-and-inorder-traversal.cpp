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
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,unordered_map<int,int>&mp,int &index , int start , int end, int n){
        if(index>=n || start>end){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[index]);
        int pos  = mp[preorder[index]];
        index++;
        root->left =  solve(inorder , preorder,mp,index,start,pos-1,n);
        root->right =  solve(inorder , preorder,mp,index,pos+1,end,n);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int ,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int n = preorder.size();
        int index =0 ;
        return solve(inorder,preorder,mp,index,0,n-1,n);
    }
};