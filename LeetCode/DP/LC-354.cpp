//354 --> Russian Doll Envelopes

//using LIS Optimal binary search O(nlogn)

class Solution {
public:
    //binary search based optimal solution
    static bool comp(vector<int>&a, vector<int>&b){
        //if width same then sort by height in desc order
        if(a[0] == b[0]) return a[1] > b[1];

        return a[0] < b[0];
    }

    int solveOptimal(vector<vector<int>>&arr){

        //sort envelopes by width (by default sort) in asc order
        //if width same then sort by height in desc order
        sort(arr.begin(), arr.end(), comp);

        if(arr.size() == 0){
            return 0;
        }

        vector<int>ans;
        //only add the height
        ans.push_back(arr[0][1]);

        for(int i=1;i<arr.size();i++){
            //check if next env can include or exclude
            if(arr[i][1] > ans.back()){
                //include the env
                ans.push_back(arr[i][1]);
            }
            else{
                //exclude
                //overwrites
                //find index greater than equal to arr[i]
                //binary search–based STL function
                int index = lower_bound(ans.begin(), ans.end(), arr[i][1]) - ans.begin();

                ans[index] = arr[i][1];

            }
        }
        return ans.size();
    }


    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        return solveOptimal(envelopes);

    }
};


// Approach:
// 1. Sort envelopes by width in ascending order, and by height in descending order
//    for equal widths. This ensures no two envelopes with same width are nested.
//
// 2. After sorting, extract only the heights and find the 
//    Longest Increasing Subsequence (LIS) on heights.
//    - If envelope[i].height > previous envelope height, it can fit inside.
//    - Otherwise, use binary search (lower_bound) to replace the first element
//      in 'ans' that is >= current height.
//
// 3. The length of the LIS (ans.size()) gives the maximum number of envelopes
//    that can be nested.
//
// Time Complexity: O(n log n) — because each height uses binary search.
// Space Complexity: O(n) — for the LIS array.

