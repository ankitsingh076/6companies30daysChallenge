class Solution
{
    public:
        long long dividePlayers(vector<int> &skill)
        {
            int n = skill.size();
            sort(skill.begin(), skill.end());
            long long sum = skill[0] + skill[n - 1];
            long long chemistrySum = 0;

            for (int i = 0; i < n / 2; ++i)
            {
                if (skill[i] + skill[n - 1 - i] != sum)
                {
                    return -1;
                }
                chemistrySum += (long long) skill[i] *skill[n - 1 - i];
            }

            return chemistrySum;
        }
};