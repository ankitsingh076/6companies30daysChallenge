class Solution {
    int curr_sum=0;
public:
    TreeNode* bstToGst(TreeNode* root) 
    {
        travelSum(root);
        return root;
    }
    
    void travelSum(TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->right)
            travelSum(root->right);
        curr_sum+=root->val;
        root->val=curr_sum;
        if(root->left)
            travelSum(root->left);
    }
};