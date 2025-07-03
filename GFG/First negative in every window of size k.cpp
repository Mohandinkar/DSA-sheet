//First negative in every window of size k


class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        deque<int>dq;
        vector<int>ans;
        
        int n = arr.size();
        
        //process the first window
        for(int i=0;i<k;i++){
            int element = arr[i];
            if(element < 0){
                dq.push_back(i);
            }
        }
        
        //process the remaining window => store ans/ removal/ add
        for(int i=k;i<n;i++){
            //storing the previous window answer
            if(dq.empty()){
                ans.push_back(0);
            }
            else{
                int index = dq.front();
                int ele = arr[index];
                ans.push_back(ele);
            }
            
            //removal of element
            if(!dq.empty() && i-dq.front() >= k){
                dq.pop_front();
            }
            
            //adding the element
            int element = arr[i];
            if(element < 0){
                dq.push_back(i);
            }
        }
        
        //storing the ans of last window
        if(dq.empty()){
            ans.push_back(0);
        }
        else{
            int index = dq.front();
            int ele = arr[index];
            ans.push_back(ele);
        }
        
        return ans;
    }
};