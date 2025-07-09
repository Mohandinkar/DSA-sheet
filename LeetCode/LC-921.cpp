//921 --> Minimum Add to Make Parentheses Valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0 ;
        stack<int>st;

        for(auto ch:s){

            if(ch == '('){
                st.push(ch);
                ans++;
            }
            else{
                if(!st.empty()){
                    st.pop();
                    ans--;
                }
                else{
                    //only closing brackets
                    ans++;
                }
            }
        }

        return ans;
    }
};

//-----------OR---------------

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char>st;

        for(auto ch:s){

           if(!st.empty() && ch == ')' && st.top() == '('){
                st.pop();
           }
           else{
             st.push(ch);
           }

          
        }

        return st.size();
    }
};