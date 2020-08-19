class Solution {
public:
    
    void Calc( string& str, char** pChar ) {
        int nIndex = 0;
        
        for( int i = 0; i < str.size(); ++i ) {
            if( '#' == str[i] ) {
                nIndex -= ( nIndex == 0 ? 0 : 1 );
            }
            else {
                (*pChar)[nIndex++] = str[i];
            }
        }
        
        (*pChar)[nIndex] = '\0';
    }
    
    bool backspaceCompare(string S, string T) {
        char* pS = new char[S.size()+1];
        char* pT = new char[T.size()+1];
        
        Calc( S, &pS );
        Calc( T, &pT );
        
        bool bResult = ( 0 == strcmp( pS, pT ) ? true : false );
        
        delete []pS;
        delete []pT;
        
        return bResult;
    }
};