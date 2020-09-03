class Solution {
public:
    
    void bt( vector<vector<int>>& result, vector<int>& nums, vector<int>& temp, int nIdx ) {
        if( nIdx >= nums.size() )
            return ;
        
        temp.push_back(nums[nIdx]);
        result.push_back(temp);
        
        bt( result, nums, temp, nIdx+1 );
        temp.pop_back();
        bt( result, nums, temp, nIdx+1 );
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        
        vector<int> temp;
        bt( result, nums, temp, 0 );
        
        return result;
    }
};