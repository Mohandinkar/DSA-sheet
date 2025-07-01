//1776 --> Car Fleet II

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double>ans(cars.size(), -1);

        stack<int>st;

        for(int i=cars.size()-1;i>=0;--i){
            //check if the car ahead of current car is faster
            while(!st.empty() && cars[st.top()][1] >= cars[i][1]){
                st.pop();
            }

            //means current car is faster and can collide to next car
            while(!st.empty()){
                //time = dis / speed
                double collTime = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);

                if(ans[st.top()] == -1 || collTime <= ans[st.top()]){
                    ans[i] = collTime;
                    break;
                }
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};