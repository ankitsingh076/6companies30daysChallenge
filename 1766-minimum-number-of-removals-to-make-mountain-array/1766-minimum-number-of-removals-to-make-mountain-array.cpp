class Solution
{
    public:
        int minimumMountainRemovals(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> inc(n, 1), dec(n, 1);

            for (int i = 0; i < n; i++)
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (nums[i] > nums[j])
                    {
                        inc[i] = max(inc[i], inc[j] + 1);
                    }
                }
            }

            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (nums[i] > nums[j])
                    {
                        dec[i] = max(dec[i], dec[j] + 1);
                    }
                }
            }

            int minRemovals = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                if (inc[i] > 1 && dec[i] > 1)
                {
                    minRemovals = min(minRemovals, n - inc[i] - dec[i] + 1);
                }
            }

            return minRemovals;
        }
};