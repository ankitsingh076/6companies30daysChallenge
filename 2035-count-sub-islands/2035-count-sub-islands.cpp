class Solution
{
    public:
        int m, n;
    vector<vector < int>> directions = {
		{ -1, 0 },
        { 0,
            -1 },
        { 0,
            1 },
        { 1,
            0 }
    };

    bool bfs(int i, int j, vector<vector < int>> &grid1, vector< vector< int>> &grid2)
    {
        grid2[i][j] = -1;	// mark as visited
        bool isSubIsland = true;

        for (auto &dir: directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n)
            {
                if (grid2[i_][j_] == 1)
                {
                    if (grid1[i_][j_] != 1)
                    {
                        isSubIsland = false;	// part of the island in grid2 is not in grid1
                    }
                    isSubIsland = bfs(i_, j_, grid1, grid2) && isSubIsland;
                }
            }
        }

        return isSubIsland;
    }

    int countSubIslands(vector<vector < int>> &grid1, vector< vector< int>> &grid2)
    {
        m = grid1.size();
        n = grid1[0].size();

        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1 && grid1[i][j] == 1)
                {
                    if (bfs(i, j, grid1, grid2))
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};