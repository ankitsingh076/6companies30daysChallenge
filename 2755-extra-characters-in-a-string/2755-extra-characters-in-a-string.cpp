class Solution {
public:
    // T.C :- O(N * N)
// S.C :- O(N + N)    

int n;
unordered_set<string> st;

int solve(int index, string &s, vector<int>& dp) {
    
    //base case
    if(index >= n) {
        return 0;
    }
    
    if(dp[index] != -1) {
        return dp[index];
    }
    
    string currStr = "";
    int minExtra = n;      //maximum possible = equal to string len
    
    for(int i=index; i<n; i++) {
        //include
        currStr.push_back(s[i]);
        
        //find string in set true or false
        //true -> return str length otherwise return 0;
        //not present in set
        int currExtra = (st.find(currStr) == st.end()) ? currStr.length() : 0;
        //futher call
        int remainingExtra = solve(i+1, s, dp);
        int totalExtra = currExtra + remainingExtra;
        
        minExtra = min(minExtra, totalExtra);
    }
    
    return dp[index] = minExtra;
}

int minExtraChar(string s, vector<string>& dictionary) {
    
    n = s.length();
    vector<int> dp(n+1, -1);
    
    for(auto &word: dictionary) {
        st.insert(word);
    }
    
    return solve(0, s, dp);
}
};