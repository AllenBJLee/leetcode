class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int nSize = matrix.size();
        vector<vector<int>> result( nSize, vector<int>(nSize, 0) );
        
        for( int i = 0; i < nSize; ++i ) {
            for( int j = 0; j < nSize; ++j ) {
                result[j][nSize-i-1] = matrix[i][j];
            }
        }
        
        matrix = result;
    }
};