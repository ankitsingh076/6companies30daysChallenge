class Solution
{
    public:
        vector<int> arrayRankTransform(vector<int> &arr)
        {
            int n = arr.size();
            unordered_map<int, int> mp;
            vector<int> temp(arr);
            sort(temp.begin(), temp.end());
            int rank = 1;
            for (int i = 0; i < n; i++)
            {
                if (i > 0 && (temp[i] - temp[i - 1]) > 0)
                {
                    rank++;
                }
                mp[temp[i]] = rank;
            }
            for (int i = 0; i < n; i++)
            {
                arr[i] = mp[arr[i]];
            }
            return arr;
        }
};