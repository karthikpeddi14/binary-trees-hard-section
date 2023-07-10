class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(root==NULL) return "";
        queue<TreeNode*> q;
        string s;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curnode= q.front();
            q.pop();
            if(curnode==NULL) s.append("#,");
            else s.append(to_string(curnode->val)+',');

            if(curnode)
            {
                q.push(curnode->left);
                q.push(curnode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(!data.size()) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            getline(s,str,',');
            if(str!="#")
            {
                temp->left = new TreeNode(stoi(str));
                q.push(temp->left);
            }
            else temp->left =NULL;

            getline(s,str,',');
            if(str!="#")
            {
                temp->right = new TreeNode(stoi(str));
                q.push(temp->right);
            }
            else temp->right = NULL;
        }

        return root;
    }
};

