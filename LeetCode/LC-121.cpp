//121 --> Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = INT_MIN;
        int minPrice = INT_MAX;

        for(int i=0;i<prices.size();i++){
            
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }

            int currProfit = prices[i] - minPrice;
            if(currProfit > maxProfit){
                maxProfit =  currProfit;
            }
        }

        return maxProfit;
    }
};