class Solution
{
    public:
        long long maxKelements(vector<int> &nums, int k)
        {
            int n = nums.size();
            priority_queue<int> pq;

            for (int i = 0; i < n; i++)
            {
                pq.push(nums[i]);
            }

            long long score = 0;
            while (k--)
            {
                int x = pq.top();
                pq.pop();
                score += x;
                pq.push(ceil(x / 3.0));
            }

            return score;
        }
};