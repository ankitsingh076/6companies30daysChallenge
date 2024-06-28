class Solution
{
    public:
        long long maximumImportance(int n, vector<vector < int>> &roads)
        {
            long long ans = 0;
            vector<int> freq(n, 0);
            for (int i = 0; i < roads.size(); i++)
            {
               	// Increment the road count for the first city.
                freq[roads[i][0]]++;
               	// Increment the road count for the second city.
                freq[roads[i][1]]++;
            }
           	//Sort the road counts to prioritize cities with fewer roads.
            sort(freq.begin(), freq.end());
           	// Sort the freq vector since  city with lowest road 
           	// should be assign lowest number.
            for (int i = 0; i < n; i++)
            {
                ans += (long long) freq[i] *(i + 1);
            }
            return ans;
        }
};