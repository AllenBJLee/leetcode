class Solution {
public:
    int maxArea(vector<int>& height) {
        int nLeft = 0;
        int nRight = height.size() - 1;
        
        int nTemp = 0;
        int nResult = 0;
        
        while( nLeft < nRight ) {
            nTemp = ( height[nLeft] < height[nRight] ? height[nLeft] : height[nRight] ) * ( nRight - nLeft );
            
            if( nResult < nTemp )
                nResult = nTemp;
            
            height[nLeft] < height[nRight] ? ++nLeft : --nRight;
        }
        
        return nResult;
    }
};