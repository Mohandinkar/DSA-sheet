//139 ---> Word Break

class Solution {
public:

    bool check(vector<string>&wordDict, string&word){
        for(auto w:wordDict){

            if(w == word) return true;
        }

        return false;
    }

    //top-down DP
    bool solveMemo(string&s, vector<string>&wordDict, int start, vector<int>&dp){
        //base case
        if(start == s.size()){
            return true;
        }

        if(dp[start] != -1)
            return dp[start];

        string word = "";
        bool flag = false;
        for(int i=start;i<s.size();i++){
            word += s[i];
            if(check(wordDict, word)){
                flag = flag || solveMemo(s, wordDict, i+1, dp);
            }
        }

        dp[start] = flag;
        return dp[start];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        //only one is varing in the rec call so 1 D DP
        vector<int>dp(s.size(), -1);

        return solveMemo(s, wordDict, 0, dp);
    }
};

/*
Approach:
-----------
- Use recursion with memoization (Top-Down DP) to check if `s` can be segmented into words from `wordDict`.  
- Start from index 0 and try every possible substring; if a prefix exists in the dictionary, recursively check the remaining part.  
- Memoize results for each starting index to avoid recomputation.  
- Base case: if we reach the end of the string, return true.  
- Time Complexity: O(n² * m) where m is the number of words in the dictionary.
*/