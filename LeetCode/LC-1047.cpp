// 1047 --> Remove All Adjacent Duplicates In String

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";

        int n = s.length();
        for(int i=0;i<n;i++){
            char currChar = s[i];

            if(ans == ""){
                ans.push_back(currChar);
            }
            else if(currChar == ans.back()){
                ans.pop_back();
            }
            else if(currChar != ans.back()){
                ans.push_back(currChar);
            }
        }

        return ans;
    }
};