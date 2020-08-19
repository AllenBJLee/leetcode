class Solution {
public:
    int Calc( int n ) {
        int nSum = 0;
        int nValue = 0;
        
        while(n > 0) {
            nValue = n % 10;
            nSum += (pow(nValue,2));
            
            n = n / 10;
        }
        
        return nSum;
    }
    
    bool isHappy(int n) {
        map<int, int> mapData;
        map<int, int>::iterator itFind;
        
        bool bResult = false;
        
        while(true) {
            itFind = mapData.find(n);
            
            if( itFind == mapData.end() ) {
                // not exists
                mapData.insert(pair<int,int>(n,n));
            }
            else {
                // enter cycle
                break;
            }
                
            if( 1 == n ) {
                bResult = true;
                
                break;
            }
            
            n = Calc(n);
        };
        
        return bResult;
    }
};