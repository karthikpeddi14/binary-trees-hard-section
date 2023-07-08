class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        if(!root) return 0;
        int ans =0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});

        while(!q.empty())
        {
            int n=q.size();
            int minn = q.front().second;
            int low,high;
            for(int i=0 ; i<n ; i++)
            {
                long long cur_id = q.front().second-minn;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) low = cur_id;
                if(i==n-1) high = cur_id;
                if(node->left) q.push({node->left,cur_id*2 +1});
                if(node->right) q.push({node->right, cur_id*2 +2});
            }
            ans = max(ans,high-low+1);
        }
        return ans;
    }
};
