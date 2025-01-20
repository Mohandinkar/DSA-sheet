//  First Repeating Element

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(vector<int> &arr) {
        // code here
        unordered_map<int,int>hashing;
        
        //store the count of each element, by default it is 0
        for(int i=0;i<arr.size();i++){
            
            hashing[arr[i]]++;
        }
        
        //if count greater than 1 => return index of element
        for(int i=0;i<arr.size();i++){
            int count = hashing[arr[i]];
            if(count > 1){
                return i+1;
            }
        }
        
        return -1;
        
    }
};