class Solution
{
    public:
        int dfs(int i, int j, int prev, vector<vector < int>> &grid)
        {
            if (i < 0 || i == grid.size() || j == grid[0].size() || prev >= grid[i][j]) return 0;
            prev = grid[i][j];
            grid[i][j] = 0;
            int res = max(max(dfs(i - 1, j + 1, prev, grid), dfs(i, j + 1, prev, grid)), dfs(i + 1, j + 1, prev, grid));
            return res + 1;
        }
    int maxMoves(vector<vector < int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) ans = max(ans, dfs(i, 0, 0, grid));
        return ans - 1;
    }
};