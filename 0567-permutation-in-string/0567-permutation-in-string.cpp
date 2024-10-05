class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if (m > n) return false; 

        vector<int> count1(26, 0);  
        vector<int> count2(26, 0);  

        
        for (int i = 0; i < m; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        for (int i = m; i < n; i++) {
            if (count1 == count2) return true;  

            count2[s2[i] - 'a']++;          
            count2[s2[i - m] - 'a']--;      
        }

        return count1 == count2;
    }
};
