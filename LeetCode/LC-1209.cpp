//1209 --> Remove All Adjacent Duplicates in String II

class Solution {
    public:
        //k = k-1
        bool checkForSameChars(string&ans, char&newChar, int k){
            int it = ans.size() - 1;
            for(int i=0;i<k;i++){
                if(ans[it] != newChar) return false;
                it--;
            }
    
            return true;
        }
        string removeDuplicates(string s, int k) {
            string ans;
            for(int i=0;i<s.size();i++){
                char&newChar = s[i];
                if(ans.size() < k-1){
                    ans.push_back(newChar);
                }
                else{
                    //check for the k-1 chars are same or not 
                    if(checkForSameChars(ans, newChar,k-1)){
                        for(int i=0;i<k-1;i++)
                            ans.pop_back();
                    }
                    else{
                        ans.push_back(newChar);
                    }
                }
            }
    
            return ans;
        }
    };