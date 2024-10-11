class Solution
{
    public:
        int maxWidthRamp(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> indices(n);

            for (int i = 0; i < n; i++)
            {
                indices[i] = i;
            }

            sort(indices.begin(), indices.end(), [& ](int i, int j)
            {
                return nums[i] != nums[j] ? nums[i] < nums[j] : i < j;
	});

            int mini = INT_MAX;
            int res = 0;

            for (int i = 0; i < n; i++)
            {
                res = max(res, indices[i] - mini);
                mini = min(mini, indices[i]);
            }

            return res;
        }
};