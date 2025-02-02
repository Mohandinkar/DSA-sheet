//14 --> Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int i = 0;

        while(true){
            char currChar = 0;

            for(auto str : strs){
                if(i >= str.size()){
                    currChar = 0;
                    break;
                }
                if(currChar == 0){
                    currChar = str[i];
                }
                else if(str[i] != currChar){
                    currChar = 0;
                    break;
                }
            }
            if(currChar == 0){
                break;
            }
            ans.push_back(currChar);
            i++;
        }
        return ans;
    }
};
