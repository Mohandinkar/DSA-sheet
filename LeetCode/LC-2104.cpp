//2104 --> Sum of Subarray 

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

    long long sumSubarrayMins(vector<int>& arr) {
       //sum of all minumum element in subarray
       auto next = nextSmallerIndex(arr); 
       auto prev = prevSmallerIndex(arr);

       long long sum = 0;
       

       for(int i=0;i<arr.size();i++){
            
            long long nexti = next[i]==-1 ? arr.size() : next[i];
            long long previ = prev[i];
            
            long long left = i - previ;
            long long right = nexti - i;

            sum += (left*right) * arr[i];
       }

       return sum;
    }


    //finding the total maximum element in subarray
    vector<int>nextGreaterIndex(vector<int>&v){
        stack<int>st;
        st.push(-1);
        vector<int>ans(v.size(), -1);

        for(int i=v.size()-1;i>=0;i--){
            int element = v[i];

            while(st.top() != -1 && v[st.top()] < element)
                st.pop();
            
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

  vector<int>prevGreaterIndex(vector<int>&v){
        stack<int>st;
        st.push(-1);
        vector<int>ans(v.size(), -1);

        for(int i=0;i<v.size();i++){
            int element = v[i];

            while(st.top() != -1 && v[st.top()] <= element)
                st.pop();
            
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
       //sum of all maximum element in subarray
       auto next = nextGreaterIndex(arr); 
       auto prev = prevGreaterIndex(arr);

       long long sum = 0;
       

       for(int i=0;i<arr.size();i++){
            
            long long nexti = next[i]==-1 ? arr.size() : next[i];
            long long previ = prev[i];
            
            long long left = i - previ;
            long long right = nexti - i;

            sum += left*right * arr[i];
       }

       return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        auto totalMaxSum = sumSubarrayMaxs(nums);
        auto totalMinSum = sumSubarrayMins(nums);

        return totalMaxSum - totalMinSum;
    }
};