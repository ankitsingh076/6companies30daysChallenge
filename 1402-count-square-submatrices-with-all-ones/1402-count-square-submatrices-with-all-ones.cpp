class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int count = 0;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 1) {
                    int upperleft   = i > 0 && j > 0 ? matrix[i - 1][j - 1] : 0;
                    int upper       = i > 0 ? matrix[i - 1][j] : 0;
                    int left        = j > 0 ? matrix[i][j - 1] : 0;
                    
                    matrix[i][j] = min({ upperleft, upper, left }) + 1;
                    
                    count += matrix[i][j];
                }
            }
        }
        
        return count;
    }
};