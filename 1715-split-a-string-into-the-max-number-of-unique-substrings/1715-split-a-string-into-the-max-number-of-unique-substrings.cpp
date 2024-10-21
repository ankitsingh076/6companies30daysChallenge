class Solution
{
    private:
        int n;
    void solve(string &s, int i, int curr, int &maxi, set<string> &st)
    {
        if (curr + (n - i) <= maxi)
        {
            return;
        }

        if (i == n)
        {
            maxi = max(maxi, curr);
        }

        for (int j = i; j < n; j++)
        {
            string str = s.substr(i, j - i + 1);
            if (st.find(str) == st.end())
            {
                st.insert(str);
                solve(s, j + 1, curr + 1, maxi, st);
                st.erase(str);
            }
        }
    }
    public:
        int maxUniqueSplit(string s)
        {
            n = s.length();
            set<string> st;
            int maxi = 0, curr = 0;
            solve(s, 0, curr, maxi, st);

            return maxi;
        }
};