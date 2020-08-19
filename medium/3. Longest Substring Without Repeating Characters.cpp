class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        string strTemp;
        size_t sFind;
        
        int nMaxSize = s.size();
        
        int nResult = 0;        
        int nTemp = 0;
        
        for( int nIndex = 0; nIndex < nMaxSize; ++nIndex ) {
            sFind = strTemp.find( s[nIndex] );
            
            if( string::npos == sFind ) {
                // found new one
                strTemp += s[nIndex];
                nTemp++;
            }
            else {
                // already exist.
                if( nResult < nTemp ) {
                    nResult = nTemp;
                }
                
                strTemp.erase( 0, sFind + 1 );
                
                strTemp += s[nIndex];
                nTemp = strTemp.size();
            }
        }
        
        
        if( nResult < nTemp )
            nResult = nTemp;
        
        return nResult;
    }
};