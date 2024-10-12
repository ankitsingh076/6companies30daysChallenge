class Solution
{
    public:
        int minGroups(vector<vector < int>> &intervals)
        {
            sort(intervals.begin(), intervals.end());
            int n = intervals.size();

            priority_queue<int, vector < int>, greater < int>> pq;
            for (int i = 0; i < n; i++)
            {

                int start = intervals[i][0];
                int end = intervals[i][1];

                if (!pq.empty() && start > pq.top())
                {
                    pq.pop();
                }

                pq.push(end);
            }

            return pq.size();
        }
};