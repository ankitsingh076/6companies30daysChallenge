class Solution
{
    public:
        int minLength(string s)
        {
            int n = s.length();

            stack<char> st;

            for (auto &ch: s)
            {

                if (!st.empty() && ch == 'B' && st.top() == 'A')
                {
                    st.pop();
                }
                else if (!st.empty() && ch == 'D' && st.top() == 'C')
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
            return st.size();
        }
};