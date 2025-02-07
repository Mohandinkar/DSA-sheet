// 5 --> Longest Palindromic Substring

//it will be solved using the DP
//it shows the Memory limit exceeded error

class Solution {
public:
    bool isPalindrome(string s, int st, int end){
        
        while(st <= end){
            if(s[st] != s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans="";

        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){

                if(isPalindrome(s, i, j)){
                    string sub = s.substr(i, j-i+1);
                    ans = sub.size() > ans.size() ? sub : ans;
                }
            }
        }
        return ans;
    }
};