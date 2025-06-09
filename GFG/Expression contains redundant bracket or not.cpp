//Expression contains redundant bracket or not

class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char ch =s[i];
            
            int count = 0;
            
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                st.push(ch);
            }
            else if(ch == ')'){
            
                while(st.top() != '('){
                    count++;
                    st.pop();
                }
                
                if(count == 0){
                    //redundant bracket
                   return 1; 
                }
                else{
                    st.pop();
                }
            }
        }
        
        return 0;
    }
};
