class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        map<int,int> mpp;
        for(int i=0; i<inorder.size() ; i++)
        {
            mpp[inorder[i]]= i;
        }
        return buildtree(inorder,postorder,mpp,0,inorder.size()-1,0,postorder.size()-1);
    }

    TreeNode* buildtree(vector<int>& inorder, vector<int>& postorder,map<int,int>& mpp, int in_start,int in_end, int post_start, int post_end)
    {
        if(in_start>in_end || post_start>post_end) return NULL;
        TreeNode* root = new TreeNode(postorder[post_end]);
        int in_root = mpp[postorder[post_end]];
        int left_nums = in_root - in_start;

        root->left = buildtree(inorder,postorder,mpp,in_start,in_root-1,post_start,post_start+left_nums-1);
        root->right = buildtree(inorder,postorder,mpp,in_root+1,in_end,post_start+left_nums,post_end-1);
        return root;
    }
};
