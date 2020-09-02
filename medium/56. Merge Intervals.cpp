class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        
        sort( intervals.begin(), intervals.end(),
            []( vector<int>& a, vector<int>& b ){ return( a[0] < b[0] ); } );
        
        // for( auto item : intervals ) {
        //     cout << "[" << item[0] << "," << item[1] << "], ";
        // }
        
        int nStart = 0;
        int nEnd = 0;
        
        int j = 0;
        
        for( int i = 0; i < intervals.size(); ++i ) {
            nStart = intervals[i][0];
            nEnd = intervals[i][1];
            
            for( j = i + 1; j < intervals.size(); ++j ) {
                if( nEnd >= intervals[j][0] ) {
                    nEnd = max( nEnd, intervals[j][1] );
                }
                else {
                    break;
                }
            }
            
            result.push_back( vector<int>{ nStart, nEnd } );
            i = j - 1;
        }
        
        return result;
    }
    
//     void Merge( const vector<int>& src, vector<int>& dest ) {
//         dest[0] = src[0] < dest[0] ? src[0] : dest[0];
//         dest[1] = src[1] > dest[1] ? src[1] : dest[1];
//     }
    
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<bool> bMerged(intervals.size(), false);
        
//         vector<vector<int>> result;
        
//         vector<int> temp(2,0);
        
//         for( int i = 0; i < intervals.size(); ++i ) {
//             if( true == bMerged[i] )
//                 continue;
            
//             temp = intervals[i];
            
//             for( int j = 0; j < intervals.size(); ++j ) {
//                 if( i == j || true == bMerged[j] )
//                     continue;
                
//                 if( (temp[0] <= intervals[j][0] && temp[1] >= intervals[j][0] ) ||
//                   ( intervals[j][0] <= temp[0] && intervals[j][1] >= temp[0] ) ) {
//                     bMerged[j] = true;
                    
//                     Merge( intervals[j], temp );
//                     j = -1;
//                 }
//             }
            
//             result.push_back( temp );
//             intervals[i] = temp;
//         }
        
//         return result;
//     }
};