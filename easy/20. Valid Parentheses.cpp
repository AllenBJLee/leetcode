class Solution {
public:
    
    bool isMatched( char a, char b ) {
        if( '(' == a ) {
            if( ')' == b )
                return true;
        }
        else if( '{' == a ) {
            if( '}' == b )
                return true;
        }
        else if( '[' == a  ) {
            if( ']' == b )
                return true;
        }
        
        return false;
    }
    
    bool isValid(string s) {
        vector< char > chVector;
        
        for( int nIndex = 0; nIndex < s.size(); ++nIndex ) {
            if( '(' == s[nIndex] || '{' == s[nIndex] || '[' == s[nIndex] ) {
                chVector.push_back( s[nIndex] );
            }
            else {
                if( 0 == chVector.size() ) {
                    chVector.push_back( s[nIndex] );
                    break;
                }
                else {
                    if( false == isMatched( chVector.back(), s[nIndex] ) ) {
                        chVector.push_back( s[nIndex] );
                        break;
                    }
                    
                    chVector.pop_back();
                }
            }
        }
        
        if( 0 < chVector.size() ) {
            return false;
        }
        
        return true;
    }
};