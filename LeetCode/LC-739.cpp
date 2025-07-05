//739 --> Daily Temperatures

//Same as next greater element in array

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //next greater element
        stack<int>st;
        st.push(0);
        vector<int>ans(temperatures.size(), 0);

        for(int i=temperatures.size()-1;i>=0;i--){

            int element = temperatures[i];

            while(st.top() != 0 && temperatures[st.top()] <= element){
                st.pop();
            }

            if(st.top() != 0){
                int nextWarmthDay = st.top() - i;
                ans[i] = nextWarmthDay;
            }

            //push to stack
            st.push(i);
        }

        return ans;
    }
};