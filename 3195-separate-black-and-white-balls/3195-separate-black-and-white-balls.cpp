class Solution
{
    public:
        long long minimumSteps(string s)
        {
            int n = s.length();
            long long cnt_black = 0;
            long long result = 0;
            for (auto &it: s)
            {
                if (it == '0')
                {
                    result += cnt_black;
                }
                else
                {
                    cnt_black++;
                }
            }
            return result;
        }
};