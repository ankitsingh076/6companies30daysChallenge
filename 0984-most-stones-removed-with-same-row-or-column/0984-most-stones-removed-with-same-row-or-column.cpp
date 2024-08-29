class Solution
{
    public:
        void dfs(vector<vector < int>> &adj, vector< bool > &visited, int stone)
        {
            visited[stone] = true;

            for (auto &it: adj[stone])
            {
                if (!visited[it])
                {
                    dfs(adj, visited, it);
                }
            }
        }

    int removeStones(vector<vector < int>> &stones)
    {
        int n = stones.size();
        int count = 0;
        vector<vector < int>> adj(n);
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(adj, visited, i);
                count++;
            }
        }

        return n - count;
    }
};