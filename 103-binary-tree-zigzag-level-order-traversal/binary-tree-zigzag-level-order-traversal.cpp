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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          vector<vector<int>> v;
        if (root == NULL)
        {
            return v;
        }
        queue<TreeNode *> q;
        vector<int> ans;
        q.push(root);
        q.push(NULL);
        int flag =1;

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                if(flag%2==0){
                    reverse(ans.begin(),ans.end());
                }
                v.push_back(ans);
                ans.clear();
                if (!q.empty())
                {
                    q.push(NULL);
                    flag++;
                }
            }
            else
            {
                ans.push_back(temp->val);

                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        return v;
    }
};