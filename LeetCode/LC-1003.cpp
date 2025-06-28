//1003 --> Check If Word Is Valid After Substitutions

//using recursion => TC => O(n^2)

class Solution {
public:
    bool isValid(string s) {
        //base case
        if(s.size() == 0){
            return true;
        }
        int found = s.find("abc");

        if(found != string::npos){
            //found in string
            string tleft = s.substr(0, found);
            string tright = s.substr(found+3, s.size());

            return isValid(tleft + tright);
        }
        return false;
    }

};


//OPTIMIZE WAY using stack
//TC=> O(n)

class Solution {
public:
    bool isValid(string s) {
      
      if(s[0] != 'a') return false;

      stack<char>st;
      for(char ch:s){
        if(ch == 'a'){
            st.push(ch);
        }
        else if(!st.empty() && ch == 'b'){
            if(!st.empty() && st.top() == 'a'){
                st.push(ch);
            }
            else{
                return false;
            }
        }
        else{

            if(!st.empty() && st.top() == 'b'){
                st.pop(); //pop b
                st.pop(); //pop a
            }
            else{
                return false;
            }
        }
      }

      return st.empty();
    }

};