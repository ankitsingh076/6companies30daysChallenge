class Solution
{
    public:
        string longestDiverseString(int a, int b, int c)
        {
            priority_queue<pair<int, char>> pq;
            if (a > 0) {
            pq.push({a, 'a'});
            }

            if (b > 0) {
                pq.push({b, 'b'});
            }

            if (c > 0) {
                pq.push({c, 'c'});
            }

            string res = "";
            while (!pq.empty())
            {
                auto it = pq.top();
                pq.pop();

                int count = it.first;
                char ch = it.second;

                if (res.length() >= 2 && res[res.length() - 1] == ch && res[res.length() - 2] == ch)
                {

                    if (pq.empty())
                    {
                        break;
                    }

                    auto x = pq.top();
                    pq.pop();

                    int count1 = x.first;
                    char ch1 = x.second;

                    res += ch1;
                    count1--;
                    if (count1 > 0)
                    {
                        pq.push({ count1,ch1 });
                    }
                    pq.push({ count,ch });
                }
                else
                {
                    res += ch;
                    count--;
                    if (count > 0)
                    {
                        pq.push({ count,ch });
                    }
                }
            }
            return res;
        }
};