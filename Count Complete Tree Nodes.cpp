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
        int left=0;
        int right=0;
        TreeNode* temp = root;
        while(temp) 
        {
            left++;
            temp = temp->left;
        }
        temp = root;
        while(temp)
        {
            right++;
            temp=temp->right;
        }
        if(left==right) return (1<<left)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};
