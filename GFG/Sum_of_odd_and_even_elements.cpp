// Sum of odd and even elements

//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findSum(int n) {
        // Code here
        int odd = 0;
        int even = 0;
        vector<int>ans;
        int i = 1;
        while( i<=n){
            if(i & 1){
                odd +=i;
                i++;
            }
            else{
               even += i; 
               i++;
            }
        }
        
        ans.push_back(odd);
        ans.push_back(even);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int> ans = ob.findSum(n);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends