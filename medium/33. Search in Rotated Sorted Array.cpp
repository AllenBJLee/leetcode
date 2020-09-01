class Solution {
public:
    int search(vector<int>& nums, int target) {
        int nSize = nums.size();
        
        vector<int>::iterator it = find( nums.begin(), nums.end(), target );
        
        if( it == nums.end() )
            return -1;
        else
            return it - nums.begin();
    }
};