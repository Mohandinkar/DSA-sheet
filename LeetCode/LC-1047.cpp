// 1047 --> Remove All Adjacent Duplicates In String


//by using string array
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

//-----------------------OR--------------------

//Using stack

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
       

        for(char ch:s){

            if(!st.empty() && st.top() == ch){
                st.pop();
            }
            else if(st.empty() || st.top() != ch){
                st.push(ch); 
            }
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

       reverse(ans.begin(), ans.end());
    
        return ans;
    }
};
