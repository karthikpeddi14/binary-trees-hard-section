class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        map<int,int> mpp;
        for(int i=0 ; i<inorder.size() ; i++)
        {
            mpp[inorder[i]] = i;
        }
        return buildtree(preorder,inorder,mpp,0,preorder.size()-1,0,inorder.size()-1);
    }

    TreeNode* buildtree(vector<int>& preorder , vector<int>& inorder, map<int,int>& mpp, int pre_start,int pre_end, int in_start, int in_end)
    {
        if(pre_end<pre_start || in_start>in_end) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int root_inorder = mpp[preorder[pre_start]];
        int left_number = root_inorder - in_start;

        root ->left = buildtree(preorder,inorder,mpp,pre_start+1,pre_start+left_number, in_start,root_inorder-1);
        root->right = buildtree(preorder,inorder,mpp,pre_start+left_number+1,pre_end,root_inorder+1,in_end);
        return root;
    }
};
