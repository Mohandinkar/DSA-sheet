//402 --> Remove K Digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        string ans;

        for(auto digit:num){

            if(k > 0){

                while(!st.empty() && st.top() > digit){
                    st.pop();
                    k--;

                    if(k == 0){
                        break;
                    }  
                }
            }
            st.push(digit);
        }

        //like 1234567 => k is remain 
        if(k > 0){
            while(!st.empty() && k){
                
                st.pop();
                k--;
            }
        }

        //store in reverse order
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        //remove leading zero
        while(ans.size() > 0 && ans.back() == '0'){
            ans.pop_back();
        }

        reverse(ans.begin() ,ans.end());

        return ans == "" ? "0" :ans;

    }
};