//Minimum Cost of ropes

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        //miin heap
         priority_queue<long long, vector<long long>, greater<long long>>pq;
         
         
         for(auto i: arr)
             pq.push(i);
             
         long long cost = 0;
         while(pq.size() != 1){
             long long ele1 = pq.top();
             pq.pop();
             
             long long ele2 = pq.top();
             pq.pop();
             
             long long sum = ele1 + ele2;
             
             pq.push(sum);
             
             cost = cost + sum;
         }
         
         
         return cost;
    }
};


/*
Approach:
1. Use a min-heap to always pick the two smallest ropes.
2. Combine them, add their sum to the cost, and push the new rope back.
3. Repeat until only one rope remains.
4. The total accumulated cost is the minimum cost.
Time Complexity: O(n log n)   (heap operations for n elements)
Space Complexity: O(n)        (heap storage)
*/