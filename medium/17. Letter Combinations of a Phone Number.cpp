class Solution {
public:
    map<char, string> m_mapData {
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs" },
        { '8', "tuv" },
        { '9', "wxyz" }
    };
    
    void combine( int nDigitIdx, const string& digits, vector<string>& result, string strResult ) {
        string strValue = m_mapData.find(digits[nDigitIdx])->second;
        string strTemp = strResult;
        for( auto item : strValue ) {
            if( 0 == nDigitIdx ) {
                strTemp.clear();
            }
            strTemp = strResult + item;
            
            if( nDigitIdx < digits.size() - 1 ) {
                combine( nDigitIdx+1, digits, result, strTemp );
            }
            else {
                result.push_back( strTemp );
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string strResult;
        
        if( 0 == digits.size() )
            return result;
        
        combine( 0, digits, result, strResult );
        
        return result;
    }
};

// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         int nMaxSize = digits.size();
        
//         if( 0 == nMaxSize ) {
//             return( vector<string>{} );
            
//         }
        
//         vector<string> result( pow( 3, nMaxSize ) );
        
//         int nIndex = 0;
//         int nKsize = 0;
//         int nDigitStart = 0;
        
//         for( int i = 0; i < nMaxSize; ++i ) {
//             nIndex = 0;
            
//             nDigitStart = 3*(digits[i]-'1')-1;
//             //cout << "digitStart : " << nDigitStart << endl;
//             //cout << "digits : " << digits[i] << "\tjSize : " << pow( 3, nMaxSize - 1 - i ) << endl;
//             //cout << "jSize : " << pow( 3, i + 1 ) << endl;
//             for( int j = 0; j < pow( 3, i + 1 ); j++ ) {
//                 //cout << "k size : " << pow( 3, nMaxSize - i - 1 ) << endl;
//                 for( int k = 0; k < pow( 3, nMaxSize - i - 1 ); ++k ) {
//                     //cout << digits[i] + 47 + ( j % 3 ) << "\t";
//                     result[nIndex++] += nDigitStart + 95 + ( j % 3 );
//                 }
                
//                 //cout << endl;
//             }
//         }
        
//         return result;
//     }
// };