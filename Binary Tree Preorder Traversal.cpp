class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(root==NULL) return {};
        vector<int> ans;
        TreeNode* cur = root;
        while(cur)
        {
            if(cur->left==NULL)
            {
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode* curleft = cur->left;
                while(curleft->right && curleft->right!=cur)
                {
                    curleft = curleft->right;
                }
                if(curleft->right==NULL)
                {
                    ans.push_back(cur->val);
                    curleft->right = cur;
                    cur = cur->left;
                }
                else
                {
                    curleft->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};
