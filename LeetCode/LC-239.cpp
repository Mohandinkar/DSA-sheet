//239 --> Sliding Window Maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;

        deque<int>dq;

        //process first window
        for(int i=0;i<k;i++){
            int element = nums[i];

            while(!dq.empty() && nums[dq.back()] < element){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        //store ans of first window
        int index = dq.front();
        ans.push_back(nums[index]);

        //process remaining windows
        for(int i=k;i<nums.size();i++){

            //removal
            if(dq.front() <= i-k){
                dq.pop_front();
            }

            //addition
            int element = nums[i];
            while(!dq.empty() && nums[dq.back()] < element){
                dq.pop_back();
            }
            dq.push_back(i);

            //store ans
            int index = dq.front();
            ans.push_back(nums[index]);
        }

        return ans;
    }
};

