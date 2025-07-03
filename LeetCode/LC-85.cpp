//85 --> Maximal Rectangle

//implemented using same algorithm pating the Largest rectangle in histogram
//by adding one by one row then send it to function

class Solution {
public:
    void nextSmallestIndex(vector<int>& heights, vector<int>&nextAns){
        stack<int>st;
        st.push(-1);
        int n = heights.size();
        for(int i=n-1;i>=0;i--){
            int element = heights[i];

            
            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }

            //element is less than top element
            nextAns.push_back(st.top());

            //current index push to stack
            st.push(i);
        }
    }

    void prevSmallestIndex(vector<int>& heights, vector<int>&prevAns){
        stack<int>st;
        st.push(-1);
        int n = heights.size();
        for(int i=0;i<n;i++){
            int element = heights[i];

            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }

            prevAns.push_back(st.top());

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

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v;
        
        int n = matrix.size();
        int m = matrix[0].size();

        //convert into interger value
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<m;j++){
                temp.push_back(matrix[i][j] - '0');
            }
            v.push_back(temp);
        }

        int area = largestRectangleArea(v[0]);

        //add up rows 
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]){
                    v[i][j] += v[i - 1][j];
                }
                else{
                    v[i][j] = 0;
                }
            }

            area = max(area, largestRectangleArea(v[i]));
        }
        
            
        return area;
        }
};