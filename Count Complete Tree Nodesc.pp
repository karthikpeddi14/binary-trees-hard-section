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
    int countNodes(TreeNode* root) 
    {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                TreeNode* temp = q.front();
                q.pop();
                ans++;
                if(temp->left==NULL) break;
                q.push(temp->left);
                if(temp->right==NULL) break;
                q.push(temp->right);
            }
        }
        return ans;
    }
};
