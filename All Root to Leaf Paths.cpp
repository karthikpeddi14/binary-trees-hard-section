void recpath(Node* root , vector<vector<int>>& ans , vector<int>& per_path)
 {
    if(root->left==NULL && root->right==NULL)
    {
        per_path.push_back(root->data);
        ans.push_back(per_path);
        return;
    }
    
    per_path.push_back(root->data);
    vector<int> temp = per_path; 
    if(root->left!=NULL) recpath(root->left,ans,per_path);
    per_path = temp;
    if(root->right!=NULL) recpath(root->right, ans,per_path);
    
 }
vector<vector<int>> Paths(Node* root)
{
    if(root == NULL) return {};
    vector<int> per_path ;
    vector<vector<int>> ans;
    recpath(root,ans,per_path);
    return ans;
}
