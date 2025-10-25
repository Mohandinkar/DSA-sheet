//140 --> Word Break II

//using recursion (without DP)
class Solution {
public:
    vector<string>solve(string&s, unordered_map<string, bool>&dict, int i){
        //base case

        if(i == s.size())
            return {""};

        vector<string>ans;
        string word;

        for(int j=i;j<s.size();j++){
            word.push_back(s[j]);

            //not found in dict
            if(dict.find(word) == dict.end()) continue;

            //found the valid word
            auto right = solve(s, dict, j+1);
            for(auto each : right){
                string endPart;
                if(each.size() > 0){
                    endPart = " " + each;
                }

                ans.push_back(word + endPart);
            }
        }
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string, bool>dict;

        for(auto word:wordDict) dict[word] = true;

        return solve(s, dict, 0);
    }
};

//using memoization (top-down DP)
class Solution {
public:
    vector<string>solveMemo(string&s, unordered_map<string, bool>&dict, int i, unordered_map<int, vector<string>>&dp){
        //base case
        if(i == s.size())
            return {""};

        if(dp.find(i) != dp.end()) return dp[i];

        vector<string>ans;
        string word;

        for(int j=i;j<s.size();j++){
            word.push_back(s[j]);

            //not found in dict
            if(dict.find(word) == dict.end()) continue;

            //found the valid word
            auto right = solveMemo(s, dict, j+1, dp);
            for(auto each : right){
                string endPart;
                if(each.size() > 0){
                    endPart = " " + each;
                }

                ans.push_back(word + endPart);
            }
        }
        dp[i] = ans;
        return dp[i];
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        //using 1D DP
        //int i correspond to string (array) so uses the map
        unordered_map<int, vector<string>>dp;
        
        unordered_map<string, bool>dict;

        for(auto word:wordDict) dict[word] = true;

        return solveMemo(s, dict, 0, dp);
    }
};


/*
Approach:
-----------
- **Goal:** Generate all possible valid sentences from string `s` by inserting spaces so that every word exists in `wordDict`.
- **Method:** Use recursion + memoization (Top-Down DP).
- From each index `i`, explore all substrings `s[i...j]`.  
  If the substring exists in the dictionary → recursively solve for `j + 1`.
- Combine current valid word with results from recursion to form complete sentences.
- Store computed results in a map `dp` (key = index, value = list of valid sentences).
- **Base Case:** When `i == s.size()`, return a list containing `""` (represents a valid end).

⏱ **Time Complexity:** O(n³)
- O(n²) for exploring all substrings (`i` to `j`)  
- O(n) extra for string concatenations and result building  
- Memoization ensures each index `i` is processed once.

💾 **Space Complexity:** O(n²)
- DP map stores results for each index with possible sentence combinations.  
- Recursion depth can go up to `n` (length of the string).
*/