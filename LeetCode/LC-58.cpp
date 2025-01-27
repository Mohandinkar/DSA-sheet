//58 --> Length of Last Word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        bool f = false;
        for(int i=s.length()-1;i>=0;i--){
            
            if(s[i] == ' ' && f){
                break;
            }
            
            else if(s[i] != ' '){
                f = true;
                ans++;
            }
        }
        return ans;
    }
};