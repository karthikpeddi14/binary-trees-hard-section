class Solution {
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        if(!root || !target) return {};
        map<TreeNode*,TreeNode*> curparent;
        map<TreeNode*,bool> visited;
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)
                {
                    curparent[temp->left] = temp;
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    curparent[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }
        while(!q.empty()){ q.pop();}
        q.push(target);
        while(k!=0 && !q.empty())
        {
            int n=q.size();
            while(n--)
            {
                TreeNode* temp = q.front();
                q.pop();
                visited[temp] = true;
                if(temp!=root && visited[curparent[temp]]==false)
                {
                    q.push(curparent[temp]);
                }
                if(temp->left!=NULL && visited[temp->left]==false)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL && visited[temp->right]==false)
                {
                    q.push(temp->right);
                }
            }
            k--;
        }
        while(!q.empty()) 
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
