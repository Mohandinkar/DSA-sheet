//20. Valid Parentheses
//using stack data structure to check if the parentheses are valid

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i=0;i<s.length();i++){

            char ch = s[i];

            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }

            else{
                if(st.empty()) return false;

                if((ch == ')' && st.top() == '(') || (ch == ']' && st.top() == '[') || (ch == '}' && st.top() == '{')){

                    st.pop();

                }
                else{

                    return false;
                }
            }
        }

        if(st.size()){
            return false;
        }else{
            return true;
        }
    }
};
