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

//-------------OR--------------
//using RE but increases the Space Complexity O(n)

class Solution {
public:

    void solve(vector<int>&prices, int i, int&minPrice, int&maxProfit){
        //base case
        if(i == prices.size())
            return;
            
        //solve one case
        if(prices[i] < minPrice) 
            minPrice = prices[i];
        
        int currProfit = prices[i] - minPrice;

        if(currProfit > maxProfit)
            maxProfit = currProfit;

        //RE
        solve(prices, i+1, minPrice, maxProfit);  
    }

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;

        solve(prices, 0, minPrice, maxProfit);

        return maxProfit;
    }
};