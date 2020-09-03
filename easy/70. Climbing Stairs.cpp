class Solution {
public:
    int climbStairs(int n) {
        if( 0 == n )
            return 0;
        
        if( 1 == n )
            return 1;
        
        if( 2 == n )
            return 2;
        
        vector<int> steps( n+1, 0 );
        steps[1] = 1;
        steps[2] = 2;
        
        for( int i = 3; i < n+1; ++i ) {
            steps[i] = steps[i-1] + steps[i-2];
        }
        
        return steps[n];
    }
};