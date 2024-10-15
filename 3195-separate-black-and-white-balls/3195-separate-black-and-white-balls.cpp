class Solution
{
    public:
        long long minimumSteps(string s)
        {
            int n = s.length();
            int curr_pos = 0;
            int white_pos = 0;
            long long swaps = 0;

            while (curr_pos < n)
            {
                if (s[curr_pos] == '0')
                    {
                        swaps += (curr_pos - white_pos);
                        white_pos++;
                    }
                    curr_pos++;
                }
                return swaps;
            }
        };