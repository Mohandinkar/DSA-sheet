//Quick Sort
// Implement Quick Sort, 
// a Divide and Conquer algorithm, to sort an array, arr[] in ascending order. 
// Given an array, arr[], with starting index low and ending index high, 
// complete the functions partition() and quickSort(). 
// Use the last element as the pivot so that all elements less than or equal to the pivot come before it, 
// and elements greater than the pivot follow it.

class Solution {
    public:
      // Function to sort an array using quick sort algorithm.
      void quickSort(vector<int>& arr, int low, int high) {
          // code here
          
          //base case 
          if(low >= high) return;
          
          int i = low-1;
          int j = low;
          int pivot = high;
          
          while(j < pivot){
              if(arr[j] < arr[pivot]){
                  i++;
                  swap(arr[i], arr[j]);
              }
              j++;
          }
          i++;
          swap(arr[i], arr[pivot]);
          
          //for left side RE
          quickSort(arr, low, i-1);
          //for right side RE
          quickSort(arr, i+1, high);
      }
  
    public:
      // Function that takes last element as pivot, places the pivot element at
      // its correct position in sorted array, and places all smaller elements
      // to left of pivot and all greater elements to right of pivot.
      int partition(vector<int>& arr, int low, int high) {
          // code here
      }
  };