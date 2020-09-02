class Solution {
public:
    
//     void pathFind( vector<vector<int>>& grid, int x, int y, int sum, int& result ) {
//         sum += grid[y][x];
        
//         if( x < grid[y].size() - 1 ) {
//             pathFind( grid, x+1, y, sum, result );
//         }
        
//         if( y < grid.size() - 1 ) {
//             pathFind( grid, x, y+1, sum, result );
//         }
        
//         if( y == grid.size()-1 && x == grid[y].size()-1 ) {
//             if( -1 == result )
//                 result = sum;
//             else
//                 result = min( sum, result );
//         }
//     }
    
//     int minPathSum(vector<vector<int>>& grid) {
//         int result = -1;
//         pathFind( grid, 0, 0, 0, result );
//         return result;
//     }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int>> sumGrid( grid.size(), vector<int>( grid[0].size(), 0 ) );
        
        int nSum = 0;
        
        for( int i = 0; i < grid.size(); ++i ) {
            nSum += grid[i][0];
            sumGrid[i][0] = nSum;
        }
        
        nSum = 0;
        
        for( int i = 0; i < grid[0].size(); ++i ) {
            nSum += grid[0][i];
            sumGrid[0][i] = nSum;
        }
        
        for( int i = 1; i < grid.size(); ++i ) {
            for( int j = 1; j < grid[i].size(); ++j ) {
                sumGrid[i][j] = min( sumGrid[i-1][j], sumGrid[i][j-1] ) + grid[i][j];
            }
        }
        
        return( sumGrid[sumGrid.size()-1][sumGrid[0].size()-1] );        
    }
};