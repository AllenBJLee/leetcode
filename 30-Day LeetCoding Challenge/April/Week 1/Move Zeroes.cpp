class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nMaxSize = nums.size();
        
        vector<int> idx;
        
        for( int i = 0; i < nMaxSize; ++i ) {
            if( 0 == nums[i] ) {
                nums.push_back(0);
                
                idx.push_back(i);
            }
        }
        
        vector<int>::iterator it;
        
        for( int i = idx.size() - 1; i >= 0; --i ) {
            it = nums.begin() + idx[i];
            
            nums.erase(it);
        }
    }
};