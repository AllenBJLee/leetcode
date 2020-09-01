class Solution {
public:
    
    void combi( vector<vector<int>>& result, vector<int>& nums, vector<bool> bVecUsed, vector<int>& temp ) {
        if( nums.size() == temp.size() ) {
            result.push_back(temp);
            
            return ;
        }
        
        for( int i = 0; i < nums.size(); ++i ) {
            if( false == bVecUsed[i] ) {
                bVecUsed[i] = true;
                temp.push_back(nums[i]);
                
                combi( result, nums, bVecUsed, temp );
                
                temp.pop_back();
                bVecUsed[i] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        vector<bool> bUsed( nums.size(), false );        
        vector<int> temp;
        combi( result, nums, bUsed, temp );
        
        return result;
    }
};