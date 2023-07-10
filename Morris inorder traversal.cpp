// for less space complexity = O(1) , tc = O(2N)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if(root==NULL) return {};
        vector<int> ans;
        TreeNode* curroot = root;
        while(curroot)
        {
            if(curroot->left==NULL)
            {
                ans.push_back(curroot->val);
                curroot = curroot->right;
            }

            else
            {
                TreeNode* _left = curroot->left;
                while(_left->right && _left->right!=curroot)
                {
                    _left = _left->right;
                }
                if(_left->right == NULL)
                {
                    _left ->right = curroot;
                    curroot = curroot->left;
                }
                else
                {
                    _left->right = NULL;
                    ans.push_back(curroot->val);
                    curroot = curroot->right;
                }
            }
        }
        return ans;
    }
};
