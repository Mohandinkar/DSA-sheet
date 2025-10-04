// 0 - 1 Knapsack Problem

class Solution {
  public:
    
    //using top-bottom dp approach
    int solveUsingMemo(vector<int> &val, vector<int> &wt, int capacity, int index,vector<vector<int>>&dp){
        
        //base case
        if(index == 0){
            if(wt[index] <= capacity){
                return val[index];
            }
            else
                return 0;
        }
        
        //step 3: check if ans already exist
        if(dp[capacity] [index] != -1){
            return dp[capacity] [index];
        }
        
        //include/exclude pattern
        
        int include = 0;
        if(wt[index] <= capacity){
            include = val[index] + solveUsingMemo(val, wt, capacity - wt[index], index - 1, dp);
            
        }
        
        int exclude = 0 + solveUsingMemo(val, wt, capacity, index - 1, dp);
        
        //step 2 : stores in the DP array
        dp[capacity] [index] = max(include, exclude);
        
        return dp[capacity] [index];
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int capacity = W;
        int n = val.size();
        int index = n-1;
        
        //step1 : create DP array
        vector<vector<int>>dp(capacity+1, vector<int>(n, -1));
        return solveUsingMemo(val, wt, capacity, index, dp);
    }
};


/*
Approach:
- This is the 0/1 Knapsack problem.  
- For each item at index i, we have two choices:
    1. Include the item → add its value and reduce remaining capacity.
    2. Exclude the item → move to next item without reducing capacity.  
- Take the maximum of these two choices.  
- Use a DP table (capacity x items) to store results of subproblems so we don’t repeat calculations.  
- Base case: when index = 0, check if that single item can fit into the capacity.  

Time Complexity: O(n * W)   // n = number of items, W = capacity  
Space Complexity: O(n * W)  // for the DP table  
*/
