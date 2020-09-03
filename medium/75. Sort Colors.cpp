class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cntSort(3, 0);
        
        for( auto item : nums ) {
            ++cntSort[item];
        }
        
        int nIdx = 0;
        
        auto Sort = [&nums, &cntSort, &nIdx](int nCurrent) {
            for( int i = 0; i < cntSort[nCurrent]; ++i )
                nums[nIdx++]=nCurrent;
        };
        
        Sort( 0 );
        Sort( 1 );
        Sort( 2 );
    }
};