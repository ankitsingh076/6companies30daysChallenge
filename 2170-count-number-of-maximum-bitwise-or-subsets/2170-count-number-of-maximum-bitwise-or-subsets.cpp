class Solution
{

    private:

        void solve(int ind, vector<int> &nums, int &ans, int m, int &maxor, int ds)
        {
            if (ind == m)
            {
                if (ds == maxor)
                {
                    ans++;
                }
                return;
            }
            solve(ind + 1, nums, ans, m, maxor, ds | nums[ind]);
            solve(ind + 1, nums, ans, m, maxor, ds);
        }

    public:
        int countMaxOrSubsets(vector<int> &nums)
        {
            const int m = nums.size();
            int maxor = 0;
            for (int i: nums)
            {
                maxor |= i;
            }
            int ds = 0;
            int ans = 0;
            solve(0, nums, ans, m, maxor, ds);
            return ans;
        }
};