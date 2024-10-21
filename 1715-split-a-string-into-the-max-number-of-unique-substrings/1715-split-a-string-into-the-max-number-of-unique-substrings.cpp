class Solution
{
    public:
        void solve(string &s, int index, int &max_count, int curr_count, unordered_set<string> &st)
        {
            if (curr_count + (s.length() - index) <= max_count)
            {
                return;
            }

            if (index == s.length())
            {
                max_count = max(max_count, curr_count);
            }

            for (int j = index; j < s.length(); j++)
            {
                string str = s.substr(index, j - index + 1);
                if (st.find(str) == st.end())
                {
                    st.insert(str);
                    solve(s, j + 1, max_count, curr_count + 1, st);
                    st.erase(str);
                }
            }
        }

    int maxUniqueSplit(string s)
    {
        unordered_set<string> st;
        int max_count = 0;
        int curr_count = 0;
        solve(s, 0, max_count, curr_count, st);

        return max_count;
    }
};