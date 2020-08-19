class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int> > mapData;
        
        map<string, vector<int> >::iterator itFind;
        
        vector< char > idx;
        int nLen = 0;
        
        string strKey;
        
        int nItemIdx = 0;
        
        for( const auto& item : strs ) {
            nLen = item.size();
            
            idx.clear();
            
            for( int nIndex = 0; nIndex < nLen; ++nIndex ) {
                idx.push_back(item[nIndex]);
            }
            
            sort(idx.begin(), idx.end());
            
            strKey.clear();
            
            for( int nIndex = 0; nIndex < idx.size(); ++nIndex ) {
                strKey += idx[nIndex];
            }
            
            //printf( "strKey:%s\t", strKey.c_str() );
            
            itFind = mapData.find( strKey );
            
            if( itFind == mapData.end() ) {
                // found new one
                //vector<int> item(1, nItemIdx);
                mapData.insert( pair<string, vector<int>>(strKey, {nItemIdx} ) );
                //printf( "idx(%d) inserted\n", nItemIdx );
            }
            else {
                itFind->second.push_back(nItemIdx);
                
                //printf( "idx(%d) added. size(%d)\n", nItemIdx, itFind->second.size() );
            }
            
            nItemIdx++;                
        }
        
        vector<vector<string>> result;
        
        for( const auto& mapItem : mapData ) {
            result.push_back({});
            
            int nCurrentIdx = result.size() - 1;
            
            for( auto idx : mapItem.second ) {
                //printf( "%s\t", strs[idx].c_str() );
                result[nCurrentIdx].push_back( strs[idx] );
            }
            
            //printf("\n");
        }
        
        return result;
    }
};