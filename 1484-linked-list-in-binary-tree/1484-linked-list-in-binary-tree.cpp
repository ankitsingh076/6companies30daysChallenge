class Solution
{
    public:
        bool isSubPath(ListNode *head, TreeNode *root)
        {
            if (!root) return false;
            return isPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
        }

    bool isPath(ListNode *head, TreeNode *root)
    {
        if (!head) return true;
        if (!root && head) return false;
        bool check = head->val == root->val;
        if (!check) return false;
        bool left = isPath(head->next, root->left);
        bool right = isPath(head->next, root->right);
        return (left || right);
    }
};