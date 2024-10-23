class Solution
{
    public:
        TreeNode* replaceValueInTree(TreeNode *root)
        {
            unordered_map<int, int> mp1;	// {level,sum}
            unordered_map<TreeNode*, int> mp2;	// {parent, sum of it's child}
            mp2[nullptr] = root->val;
            queue<TreeNode*> que1;
            que1.push(root);
            int level = 1;
            while (!que1.empty())
            {
                int n = que1.size();
                int level_sum = 0;
                for (int i = 0; i < n; i++)
                {
                    TreeNode *node = que1.front();
                    que1.pop();
                    int child_sum = 0;
                    level_sum += node->val;

                    if (node->left)
                    {
                        child_sum += node->left->val;
                        que1.push(node->left);
                    }
                    if (node->right)
                    {
                        child_sum += node->right->val;
                        que1.push(node->right);
                    }
                    mp2[node] = child_sum;
                }
                mp1[level] = level_sum;
                level++;
            }

            queue<pair<TreeNode*, TreeNode*>> que2;	// {child,parent}
            que2.push({ root,
                nullptr });

            int curr_level = 1;
            while (!que2.empty())
            {
                int n = que2.size();
                for (int i = 0; i < n; i++)
                {

                    TreeNode *child = que2.front().first;
                    TreeNode *parent = que2.front().second;

                    que2.pop();

                    int total_sum = mp1[curr_level];
                    int siblings_sum = mp2[parent];

                    int cousins_sum = total_sum - siblings_sum;
                    child->val = cousins_sum;

                    if (child->left)
                    {
                        que2.push({ child->left,
                            child });
                    }
                    if (child->right)
                    {
                        que2.push({ child->right,
                            child });
                    }
                }
                curr_level++;
            }
            return root;
        }
};