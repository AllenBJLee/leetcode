class Solution {
public:
    int jump(vector<int>& nums) {
        int nMaxIdx = 0;
        int nResult = 0;
        int nTemp = 0;
        
        int nSize = nums.size();
        
        for( int i = 0; i < nSize - 1; ++i ) {
            if( nMaxIdx < i + nums[i] ) {
                // 범위 내 최대로 갈 수 있는 값을 구한다.
                nMaxIdx = i + nums[i];
            }
            
            if( nTemp == i ) {
                // 이전에 지정된 최대값에 도달하면 점프 회수를 추가하고
                // 다음 최대값을 지정한다.
                nTemp = nMaxIdx;
                ++nResult;
            }
        }
        
        return nResult;
    }
};