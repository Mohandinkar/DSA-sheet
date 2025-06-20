//907 --> Sum of Subarray Minimums

class Solution {
public:
    vector<int>nextSmallerIndex(vector<int>&v){
        stack<int>st;
        st.push(-1);
        vector<int>ans(v.size(), -1);

        for(int i=v.size()-1;i>=0;i--){
             int element = v[i];

             while(st.top() != -1 && v[st.top()] > element)
                st.pop();

            ans[i] = st.top();
            st.push(i); 
        }

        return ans;  
    }

    vector<int>prevSmallerIndex(vector<int>&v){
        stack<int>st;
        st.push(-1);
        vector<int>ans(v.size(), -1);

        for(int i=0;i<v.size();i++){
             int element = v[i];

             while(st.top() != -1 && v[st.top()] >= element)
                st.pop();

            ans[i] = st.top();
            st.push(i); 
        }

        return ans;  
    }

    int sumSubarrayMins(vector<int>& arr) {
       auto next = nextSmallerIndex(arr); 
       auto prev = prevSmallerIndex(arr);

       int sum = 0;
       const int mod = 1e9 + 7;

       for(int i=0;i<arr.size();i++){
            
            int nexti = next[i]==-1 ? arr.size() : next[i];
            int previ = prev[i];
            
            int left = i - previ;
            int right = nexti - i;
            long long no_of_times = (left%mod*right%mod)%mod;
            long long total = (no_of_times * arr[i])%mod;

            sum = (sum + total)%mod;
       }

       return sum;
    }
};
