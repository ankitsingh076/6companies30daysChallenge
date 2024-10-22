class Solution
{
    public:
        long long kthLargestLevelSum(TreeNode *root, int k)
        {
            long long result = 0;
            priority_queue < long long > pq;
            queue<TreeNode*> que;
            que.push(root);
            while (!que.empty())
            {
                int n = que.size();
                long long sum = 0;
                for (int i = 0; i < n; i++)
                {
                    TreeNode *node = que.front();
                    que.pop();
                    sum += node->val;

                    if (node->left)
                    {
                        que.push(node->left);
                    }
                    if (node->right)
                    {
                        que.push(node->right);
                    }
                }
                pq.push(sum);
            }

            if (pq.size() < k) return -1;

            while (k - 1 > 0)
            {
                pq.pop();
                k--;
            }
            return pq.top();
        }
};