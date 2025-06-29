//394 -->Decode String

//using the stack data structure


class Solution {
public:
    string decodeString(string s) {
        stack<string>st;

        for(auto ch:s){
            if(ch == ']'){
                string stringToRepeat = "";
                while(!st.empty() && st.top() != "["){
                    string top = st.top();
                    stringToRepeat += top;

                    st.pop();
                }
                st.pop();

                string numericStr = "";
                while(!st.empty() && isdigit(st.top()[0])){

                    numericStr += st.top();

                    st.pop();
                }

                //reverse
                reverse(numericStr.begin(), numericStr.end());

                //convert to integer
                int n = stoi(numericStr);


                //final decoding
                string currDecodeStr="";
                while(n--){
                    currDecodeStr += stringToRepeat;
                }

                st.push(currDecodeStr);

            }
            else{
                //convert char to string 
                string temp(1, ch);

                st.push(temp);
            }
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();

            st.pop();
        }

        //reverse the string
        reverse(ans.begin(), ans.end());

        return ans;
    }
};