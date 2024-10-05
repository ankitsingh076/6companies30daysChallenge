class Solution
{
    public:
        bool checkInclusion(string s1, string s2)
        {
            int m = s1.length();
            int n = s2.length();

            unordered_map<char, int> mp1;
            unordered_map<char, int> mp2;

            for (int i = 0; i < m; i++)
            {
                mp1[s1[i]]++;
            }

            mp2 = mp1;

            int i = 0;

            while (i < n)
            {
                int j = i;

                while (mp2.find(s2[j]) != mp2.end())
                {
                    mp2[s2[j]]--;
                    if (mp2[s2[j]] == 0)
                    {
                        mp2.erase(s2[j]);
                    }
                    j++;
                }
                if (mp2.size() == 0)
                {
                    return true;
                }
                else
                {
                    mp2 = mp1;
                    i++;
                }
            }

            return false;
        }
};