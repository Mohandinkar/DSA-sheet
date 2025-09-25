//Merge k Sorted Arrays



class Info{
    public:
        int data;
        int r_index;
        int c_index;
        
        Info(int x, int y, int z){
            this->data = x;
            this->r_index = y;
            this->c_index = z;
        }
};

//returns true if the order is “wrong” and swapping is needed, or false if the order is correct.
class compare{
    public:
        
       bool operator()(Info* a, Info* b){
            return a->data > b->data;
       }
           
};


class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // code here
        
        //min heap using custom comparator
        priority_queue<Info*, vector<Info*>, compare>pq;
        
        vector<int>ans;
        
        int rowSize = arr.size();
        int colSize = arr[0].size();
        
        
        //insert the first element of each k size into the heap 
        for(int i=0;i<rowSize;i++){
            int element = arr[i][0];
            Info* temp = new Info(element, i, 0);
            
            pq.push(temp);
        }
        
        
        while(!pq.empty()){
            Info* front = pq.top();
            pq.pop();
            
            int front_data = front->data;
            int front_rindex = front->r_index;
            int front_cindex = front->c_index;
            
            ans.push_back(front_data);
            
            if(front_cindex + 1 < colSize){
                int element = arr[front_rindex][front_cindex+1];
                
                Info* temp = new Info(element, front_rindex, front_cindex + 1);
                
                pq.push(temp);
            }
        }
        
        return ans;
        
    }
};


/*
Approach:
We need to merge K sorted arrays into a single sorted list.  
The idea is to use a Min-Heap (priority_queue with custom comparator).  

Steps:
1. Create a custom class `Info` to store (value, row index, column index).  
2. Push the first element of each array into the Min-Heap.  
3. Repeatedly extract the smallest element from the heap and add it to the result.  
   - If the extracted element has a next element in the same array, push it into the heap.  
4. Continue until the heap is empty → all elements are merged in sorted order.  

Why it works:
- The heap always stores the current smallest candidates from each array.  
- By extracting the min and pushing the next element from that array, 
  we maintain the global sorted order.  

Time Complexity: O(N log K)  
- N = total number of elements across all arrays.  
- Each insertion/extraction in heap costs log K.  

Space Complexity: O(K)  
- Heap stores at most one element from each array at a time.  
*/
