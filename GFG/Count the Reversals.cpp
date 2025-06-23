//Count the Reversals

class Solution {
  public:
    int countMinReversals(string s) {
        // code here
        
        //if odd length there is no possibilty to balanced the brackets
        if(s.length() & 1) return -1;
        
        stack<char>st;
        int ans = 0;
        
        //valid parantheses => remove the valid pairs 
        for(char ch : s){
            
            if(ch == '{'){
                st.push(ch);
            }
            else{
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
            
        }
        
        //if stack not empty balanced the remainig brackets
        while(!st.empty()){
            char a = st.top();
            st.pop();
            char b = st.top();
            st.pop();
            
            //if both brackets are same just change one bracket
            if(a == b)
                ans += 1;
            //if not then change both bracket to balance
            else
                ans += 2;
        }
        
        return ans;
    }
};