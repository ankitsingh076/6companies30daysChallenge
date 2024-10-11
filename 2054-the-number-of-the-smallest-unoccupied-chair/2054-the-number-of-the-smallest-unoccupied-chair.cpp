class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int nextChair = 0;
        int targetStart = times[targetFriend][0];
        
        sort(times.begin(), times.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leave_chair;
        priority_queue<int, vector<int>, greater<int>> available_chairs;

        for (auto& time : times) {
            int start = time[0], leave = time[1];

            while (!leave_chair.empty() && leave_chair.top().first <= start) {
                available_chairs.push(leave_chair.top().second);
                leave_chair.pop();
            }

            int sat;
            if (!available_chairs.empty()) {
                sat = available_chairs.top();
                available_chairs.pop();
            } else {
                sat = nextChair++;
            }

            leave_chair.push({leave, sat});

            if (start == targetStart) {
                return sat;
            }
        }

        return -1; 
    }
};