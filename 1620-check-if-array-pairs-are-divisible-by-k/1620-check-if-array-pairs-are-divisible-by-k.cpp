class Solution
{
    public:
        bool canArrange(vector<int> &arr, int k)
        {
            map<int, int> mp;
            for (auto &it: arr)
            {
                it = ((it % k) + k) % k;
                mp[it]++;
            }
            for (auto it: arr)
            {
                if (it != 0 && mp[it] != 0)
                {
                    if (mp[k - it] == 0) return 0;
                    mp[it]--, mp[k - it]--;
                }
            }
            return !(mp[0] &1);
        }
};