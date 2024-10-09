class Solution
{
    public:
        int minAddToMakeValid(string s)
        {
            int open_brackets = 0;
            int close_brackets = 0;

            for (auto &ch: s)
            {
                if (ch == '(')
                {
                    open_brackets++;
                }
                else
                {
                    if (open_brackets > 0)
                    {
                        open_brackets--;
                    }
                    else
                    {
                        close_brackets++;
                    }
                }
            }
            return open_brackets + close_brackets;
        }
};