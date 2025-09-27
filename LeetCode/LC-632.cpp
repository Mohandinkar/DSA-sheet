//632 --> Smallest Range Covering Elements from K Lists


class Info{
    public:
    int data;
    int rIndex;
    int cIndex;

    Info(int a, int b, int c){
        this->data = a;
        this->rIndex = b;
        this->cIndex = c;
    }
};


//min heap creation using custom compartor
class compare{
    public:

    bool operator()(Info* a, Info* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        //min heap creation
        priority_queue<Info*, vector<Info*>, compare>pq;

        vector<int>ans;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int row = 0;row<nums.size();row++){

            int element = nums[row][0];
            Info* temp = new Info(element, row, 0);
            pq.push(temp);

            maxi = max(maxi, element);
            mini = min(mini, element);
        }

        int start = mini;
        int end = maxi;

        while(!pq.empty()){
            Info* front = pq.top();
            pq.pop();

            int frontData = front->data;
            int front_rIndex = front->rIndex;
            int front_cIndex = front->cIndex;

            mini = frontData;

            if((maxi - mini) < (end - start)){
                start = mini;
                end = maxi;
            }

            int currentColSize = nums[front_rIndex].size();
            
            if(front_cIndex + 1 < currentColSize){
                int element = nums[front_rIndex][front_cIndex + 1];

                Info* temp = new Info(element, front_rIndex, front_cIndex + 1);

                pq.push(temp);

                maxi = max(maxi, element);
            }
            else{

                break;
            }
        }

        ans.push_back(start);
        ans.push_back(end);

        return ans;


    }
};


/*
Approach:
We are given K sorted lists and need to find the smallest range [start, end] 
that includes at least one number from each list.

Key Idea: Use a Min-Heap to always track the smallest element across lists, 
while also maintaining the maximum element seen so far.

Steps:
1. Push the first element of each list into a Min-Heap (store value, row index, col index).  
   - Track both the current minimum (from heap) and maximum (separately).  
2. Initialize the range [start, end] = [min, max].  
3. Repeatedly:
   - Pop the smallest element (min) from the heap.  
   - Update the range if the current [max - min] is smaller than the previous best.  
   - If the popped element has a next element in the same list → push it into the heap,  
     and update `max` if necessary.  
   - If any list is exhausted (no more elements to push), stop.  
4. The best recorded [start, end] is the smallest range.

Why it works:
- At each step, the heap guarantees we are considering one element from every list.  
- By expanding only the list that contributed the minimum, we ensure the window 
  gradually covers all lists while minimizing the range.

Time Complexity: O(N log K)  
- N = total number of elements across all lists.  
- Each push/pop in heap costs log K.  

Space Complexity: O(K)  
- Heap stores at most one element from each list.  
*/
