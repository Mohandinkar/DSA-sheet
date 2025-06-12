//84 --> Largest Rectangle in Histogram

class Solution {
public:
    void nextSmallestIndex(vector<int>& heights, vector<int>&nextAns){
        stack<int>st;
        st.push(-1);
        for(int i=heights.size()-1;i>=0;i--){
            int element = heights[i];

            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }

            //element is less than top element
            nextAns.push_back(st.top());

            //current number push to stack
            st.push(i);
        }
    }

    void prevSmallestIndex(vector<int>& heights, vector<int>&prevAns){
        stack<int>st;
        st.push(-1);
        for(int i=0;i<heights.size();i++){
            int element = heights[i];

            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }

            //element is less than top element
            prevAns.push_back(st.top());

            //current number push to stack
            st.push(i);
        }
        
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>nextAns;
        vector<int>prevAns;

        nextSmallestIndex(heights, nextAns);
        //ans will be in revrerse format make it right 
        reverse(nextAns.begin(), nextAns.end());
     
        //IMP => for next index -1 replace with size to get difference properly
        for(int i=0;i<nextAns.size();i++){
            if(nextAns[i] == -1){
                nextAns[i] = nextAns.size();
            }
        }

        prevSmallestIndex(heights, prevAns);

        int maxArea = INT_MIN;

        for(int i=0;i<heights.size();i++){
            int width = nextAns[i]- prevAns[i] - 1;
            int height = heights[i];
            int currentArea = width * height;

            maxArea = max(maxArea, currentArea);
        } 

        return maxArea;
    }
    
};