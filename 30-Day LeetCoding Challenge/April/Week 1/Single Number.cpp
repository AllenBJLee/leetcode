class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mapData;
        map<int, int>::iterator itFind;
        
        int nResult = 0;
        
        for( auto& item : nums )
        {
            itFind = mapData.find( item );
            
            if( itFind == mapData.end() )
            {
                mapData.insert( pair<int, int>( item, 1 ) );
            }
            else
            {
                itFind->second++;
                //mapData.erase( itFind );
            }
        }
        
        for( auto& item : mapData )
        {
            if( 1 == item.second )
            {
                nResult = item.first;
                
                break;
            }
        }
        
        return nResult;
    }
};