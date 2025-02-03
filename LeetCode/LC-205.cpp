
//205 --> Isomorphic Strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //used to store the mapping of the 's' to the 't'
        int hash[256] = {0};
        //to check the character is mapped or not in t[i]
        int istCharMapped[256] = {0};

        for(int i=0;i<s.size();i++){

            if(hash[s[i]]== 0 && istCharMapped[t[i]] == 0){
                hash[s[i]] = t[i];
                istCharMapped[t[i]] = true;
            }
        }

        //for checking the char is mapped or not  
        for(int i=0; i<s.size(); i++){
            if(hash[s[i]] != t[i]){
                return false;
            }
        }
        return true;
    }
};