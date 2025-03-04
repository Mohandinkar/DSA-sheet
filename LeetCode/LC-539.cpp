//539 --> Minimum Time Difference
//Given a list of 24-hour clock time points in "HH:MM" format, 
//return the minimum minutes difference between any two time-points in the list.

class Solution {
    public:
    
        int convertToMin(string&time){
            int hr = stoi(time.substr(0,2));
            int min = stoi(time.substr(3,2));
    
            return 60 * hr + min;
        }
    
        int findMinDifference(vector<string>& timePoints) {
            vector<int>mins;
    
            for(auto time:timePoints){
                mins.push_back(convertToMin(time));
            }
    
            sort(mins.begin(), mins.end());
    
            int ans = INT_MAX;
            for(int i=0;i<mins.size()-1;i++){
                ans = min(ans, mins[i+1] - mins[i]);
            }
    
            //last difference handle
            int lastDiff = mins[0] + 1440 - mins[mins.size()-1];
    
            ans = min(ans, lastDiff);
    
            return ans;
        }
    };