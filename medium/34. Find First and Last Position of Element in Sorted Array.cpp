    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> result(2, -1);

            int nSize = nums.size();

            for( int i = 0; i < nSize; ++i ) {
                if( target == nums[i] ) {
                    result[0] = i;

                    while( i < nSize && target == nums[i] ) {
                        result[1] = i;
                        ++i;
                    }
                    break;
                }
            }

            return result;
        }
    };