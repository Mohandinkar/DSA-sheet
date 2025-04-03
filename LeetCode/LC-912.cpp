//912 --> Sort an Array

class Solution {
    public:
    
        void merge(vector<int>&nums, vector<int>&temp, int start, int mid, int end){
            int i=start, j = mid+1, k = start;
    
            while(i<=mid && j<= end){
                if(nums[i] <= nums[j]){
                    temp[k++] = nums[i++];
                }
                else{
                    temp[k++] = nums[j++];
                }
            }
    
            while(i<=mid) temp[k++] = nums[i++];
            while(j<=end) temp[k++] = nums[j++];
    
            while(start <= end){
                nums[start] = temp[start];
                start++;
            }
        }
        void mergeSort(vector<int>&nums, vector<int>&temp, int start, int end){
            //base case
            if(start >= end) return ;
    
            int mid = (start+end)/2;
            mergeSort(nums, temp, start, mid);
            mergeSort(nums, temp, mid+1, end);
    
            merge(nums, temp, start, mid, end);
        }
        vector<int> sortArray(vector<int>& nums) {
            vector<int>temp(nums.size(),0);
    
            mergeSort(nums, temp, 0, nums.size()-1);
            return nums;
        }
    };

//-----------------------OR--------------------
//Using Gap method for merge sort in Placed merge sort
//Space complexity is O(1) in this case

class Solution {
    public:
    
        void inPlaceMerge(vector<int>&nums,  int start, int mid, int end){
            int total_len = end - start + 1;
            int gap = (total_len/2) + (total_len%2); //ceil => upper value 
            while(gap > 0){
                int i=start, j =start+gap;
    
                while(j<=end){
                    if(nums[i] > nums[j]){
                        swap(nums[i], nums[j]);
                    }
                    ++i, ++j;
                }
    
                gap = gap<=1 ? 0 : (gap/2) + (gap%2);
            }
    
    
           
        }
        void mergeSort(vector<int>&nums, int start, int end){
            //base case
            if(start >= end) return ;
    
            int mid = (start+end)/2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid+1, end);
    
            inPlaceMerge(nums, start, mid, end);
        }
        vector<int> sortArray(vector<int>& nums) {
           
    
            mergeSort(nums, 0, nums.size()-1);
            return nums;
        }
    };