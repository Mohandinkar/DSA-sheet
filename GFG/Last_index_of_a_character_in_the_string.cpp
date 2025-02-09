//Last index of a character in the string


class Solution{
    public:
    
    int LastIndex(string s, char p){
        //complete the function here
        int ans;
        for(int i=0;i<s.size();i++){
            if(s[i] == p){
                ans = i;
            }
        }
        if(ans < s.size()){
            return ans;
        }
     
            return -1;
        
    }
};