//1691 --> Maximum Height by Stacking Cuboids


//using only recursion but got the TLE
class Solution {
public:

    bool isSafeToPlace(vector<int>c1, vector<int>c2){
        //checking all the rules
        if(c1[0] <= c2[0] && c1[1]<= c2[1] && c1[2] <= c2[2]){
            return true;
        }

        return false;
    }

    int solve(vector<vector<int>>& cuboids, int prev, int curr){

        //base case
        if(curr >= cuboids.size()){
            return 0;
        }

        int include = 0;
        if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr])){
            include = cuboids[curr][2] + solve(cuboids, curr, curr+1);
        }

        int exclude = 0 + solve(cuboids, prev, curr+1);

        return max(include, exclude);

    }
    int maxHeight(vector<vector<int>>& cuboids) {

        //sort the each cuboid so we get max height at 2 nd index
        //&cuboid => change in actual vector not creates the copy 
        for(auto &cuboid : cuboids){
            sort(cuboid.begin(), cuboid.end());
        }

        sort(cuboids.begin(), cuboids.end());

        int prev = -1;
        int curr = 0;

        return solve(cuboids, prev, curr);
    }
};



//optimized using memoization DP(top-down)
class Solution {
public:

    bool isSafeToPlace(vector<int>c1, vector<int>c2){
        //checking all the rules
        if(c1[0] <= c2[0] && c1[1]<= c2[1] && c1[2] <= c2[2]){
            return true;
        }

        return false;
    }

    //solve using memoisation (top-down) 2DP
    int solve(vector<vector<int>>& cuboids, int prev, int curr, vector<vector<int>>&dp){

        //base case
        if(curr >= cuboids.size()){
            return 0;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        int include = 0;
        if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr])){
            include = cuboids[curr][2] + solve(cuboids, curr, curr+1, dp);
        }

        int exclude = 0 + solve(cuboids, prev, curr+1, dp);

        dp[curr][prev+1] = max(include, exclude);
        return dp[curr][prev+1];

    }
    int maxHeight(vector<vector<int>>& cuboids) {

        vector<vector<int>>dp(cuboids.size()+1, vector<int>(cuboids.size()+1, -1));

        //sort the each cuboid so we get max height at 2 nd index
        //&cuboid => change in actual vector not creates the copy 
        for(auto &cuboid : cuboids){
            sort(cuboid.begin(), cuboid.end());
        }

        sort(cuboids.begin(), cuboids.end());

        int prev = -1;
        int curr = 0;

        return solve(cuboids, prev, curr, dp);
    }
};

//using bottom-up (iterative) tabulation
class Solution {
public:
    bool isSafeToPlace(vector<int>c1, vector<int>c2){
        //checking all the rules
        if(c1[0] <= c2[0] && c1[1]<= c2[1] && c1[2] <= c2[2]){
            return true;
        }

        return false;
    }

    //solve using tabulation (bottom-up iterative) 2DP
    int solveByTabulation(vector<vector<int>>& cuboids){
        //curr 
        //prev
        int n = cuboids.size();

        //base case analysis so initialize as 0
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        //curr => 0 -> n
        //prev => -1 -> curr

        //reverse the loop conditions 
        //n ka ans nikala hua hai already so start from n-1
        for(int curr=n-1;curr>=0;curr--){
            for(int prev = curr-1; prev>=-1;prev--){
                int include = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr])){
                    include = cuboids[curr][2] + dp[curr+1][curr+1];
                }
                int exclude = 0 + dp[curr+1][prev+1];

                dp[curr][prev+1] = max(include, exclude);  
            }
        }

        //return as mentioned in initilization of the recusrion => curr = 0 & prev = -1
        //-1 not valid index then +1 in each prev in dp to make it valid index
        return dp[0][-1+1];

    }

    int maxHeight(vector<vector<int>>& cuboids) {

        //sort the each cuboid so we get max height at 2 nd index
        //&cuboid => change in actual vector not creates the copy 
        for(auto &cuboid : cuboids){
            sort(cuboid.begin(), cuboid.end());
        }

        sort(cuboids.begin(), cuboids.end());

        int prev = -1;
        int curr = 0;

        return solveByTabulation(cuboids);
    }
};


// Approach
// Sort dimensions of each cuboid individually so height is the largest dimension.
// Sort the list of cuboids to make stacking comparisons consistent.
// Use recursion with two parameters:
// prev: index of the last placed cuboid (-1 if none yet).
// curr: index of the cuboid we are currently deciding to include/exclude.
// At each step:
// Include current cuboid if it can be placed on top of prev.
// Exclude current cuboid and move to the next.
// Return the maximum height from both choices.