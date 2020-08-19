class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int nBuy = prices[0];
        int nSell = 0;
        
        int nSumProfit = 0;
        
        int nTempSell = 0;
        
        for( auto price : prices ) {
            if( nSell == 0 && nBuy > price ) {
                // not selling time
                nBuy = price;
                
                continue;
            }
            
            if( nBuy < price ) {
                nTempSell = price - nBuy;
                
                if( nTempSell > nSell ) {
                    nSell = nTempSell;
                }
                else {
                    printf( "buy:%d nSell:%d current price : %d\n", nBuy, nSell, price );
                    nSumProfit += nSell;
                    nBuy = price;
                    nSell = 0;
                }
            }
            else if( nSell > 0 )
            {
                printf( "buy:%d nSell:%d current price : %d\n", nBuy, nSell, price );
                    nSumProfit += nSell;
                    nBuy = price;
                    nSell = 0;
            }
        }
        
        if( 0 < nSell )
            nSumProfit += nSell;
        
        return nSumProfit;
    }
};