//Allocate Minimum Pages


// You are given an array arr[] of integers, where each element arr[i] 
//represents the number of pages in the ith book.
//You also have an integer k representing the number of students. 
//The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, 
//find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: Return -1 if a valid assignment is not possible, and 
//allotment should be in contiguous order (see the explanation for better understanding).

class Solution {
  public:
  
    bool isPossibleSolution(vector<int>&arr,int k, int sol){
        int pageSum = 0;
        int count  = 1;
        
        for(int i=0;i<arr.size();i++){
            
            if(arr[i] > sol){
                return false;
            }
            if(pageSum+arr[i] > sol){
                count++;
                pageSum = arr[i];
                
                if(count > k){
                    return false;
                }
            }
            else{
                pageSum += arr[i];
            }
        }
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int start = 0;
        int end = accumulate(arr.begin(),arr.end(),0);
        int ans = -1;
        
        if(k > arr.size())
        return -1;
        
        while(start<=end){
            
            int mid = (start+end) >> 1;
            
            if(isPossibleSolution(arr,k,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};