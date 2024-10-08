class Solution
{
    public:
        int minSwaps(string s)
        {
            stack<char> st;
            for (auto &ch: s)
            {
                if (!st.empty() && ch == ']' && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    if (ch == '[')
                    {
                        st.push(ch);
                    }
                }
            }
            return (st.size() + 1) / 2;
        }
};