class Solution {
public:
    
    bool FindPath(
        vector<vector<char>>& board,
        string& word,
        int nIdx,
        int x,
        int y
    ) {
        bool bResult = false;
        
        if( nIdx == word.size() )
            return true;
        
        if( x < 0 || y < 0 || x >= board[0].size() || y >= board.size() )
            return false;
        
        if( word[nIdx] == board[y][x] ) {
            // prevent re entry
            board[y][x] = '-1';
            
            // try to trace again
            bResult =   FindPath( board, word, nIdx+1, x+1, y ) ||
                        FindPath( board, word, nIdx+1, x-1, y ) ||
                        FindPath( board, word, nIdx+1, x, y+1 ) ||
                        FindPath( board, word, nIdx+1, x, y-1 );
            
            board[y][x] = word[nIdx];
        }
        
        return bResult;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        bool bResult = false;
        
        int x = 0;
        int y = 0;
        
        for( int i = 0; i < board.size(); ++i ) {
            for( int j = 0; j < board[0].size(); ++j ) {
                // find first char
                if( word[0] == board[i][j] ) {
                    // try to trace
                    bResult = FindPath( board, word, 0, j, i );
                    
                    if( true == bResult ) {
                        return bResult;
                    }
                        
                }
            }
        }
        
        return bResult;
        
    }
};