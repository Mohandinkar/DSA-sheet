//26 --> Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =1,j=0;

        while(i<nums.size()){

            //Duplicate then move the i
            if(nums[i] == nums[j])
            i++;

            //if unique then move the j and assign the value of nums[i]
            else nums[++j] = nums[i++];
            // else{
            //     j++;
            //     nums[j] = nums[i];
            //     i++;
            // }
        } 
        return j+1;  
    }
};