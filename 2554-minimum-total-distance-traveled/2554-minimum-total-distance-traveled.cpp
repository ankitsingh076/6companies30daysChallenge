class Solution
{
    public:
        long long solve(int ri, int fi, vector<int> &robot, vector<int> &positions, vector< vector< long long>> &t)
        {
            if (ri >= robot.size())
            {
                return 0;
            }

            if (fi >= positions.size())
            {
                return 1e12;
            }

            if (t[ri][fi] != -1)
            {
                return t[ri][fi];
            }

            long long take_curr_factory = abs(robot[ri] - positions[fi]) + solve(ri + 1, fi + 1, robot, positions, t);
            long long not_take_curr_factory = solve(ri, fi + 1, robot, positions, t);

            return t[ri][fi] = min(take_curr_factory, not_take_curr_factory);
        }

    long long minimumTotalDistance(vector<int> &robot, vector<vector< int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> positions;
        for (int i = 0; i < factory.size(); i++)
        {
            int pos = factory[i][0];
            int limit = factory[i][1];

            for (int j = 0; j < limit; j++)
            {
                positions.push_back(pos);
            }
        }

        int m = robot.size();
        int n = positions.size();

        vector<vector < long long>> t(m + 1, vector < long long > (n + 1, -1));

        return solve(0, 0, robot, positions, t);
    }
};