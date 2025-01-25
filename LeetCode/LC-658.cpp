// 658 --> Find K Closest Elements

//1st method by using two pointers approach
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // vector<int>ans;
        int l=0, h=arr.size()-1;

        while(h-l >= k){

            if(x-arr[l] > arr[h]-x){
                l++;
            }
            else{
                h--;
            }
        }

        // for(int i=l;i<=h;i++){
        //     ans.push_back(arr[i]);
        // }

        return vector<int>(arr.begin()+l,arr.begin()+(h+1));
    }
};


//--------------OR---------------
//2nd method by using the binary search method

class Solution {
public:

    int lowerBound(vector<int>&arr, int x){
        int st = 0, end = arr.size()-1;
        int ans = end;

        while(st <= end){
            int mid = (st+end)/2;
            if(arr[mid] >= x){
                ans = mid;
                end=mid-1;
            }

            else if(x > arr[mid]){
                st = mid+1;
            }
            else{
                end = mid-1;
            }
            
        }
        return ans;
    }

    vector<int>bs_method(vector<int>&arr,int k, int x){
        int h = lowerBound(arr,x);
        int l = h-1;

        while(k--){
            if(l<0){
                h++;
            }
            else if(h >= arr.size()){
                l--;
            }
            else if(x-arr[l] > arr[h]-x){
                h++;
            }
            else{
                l--;
            }
        }

        return vector<int>(arr.begin()+(l+1), arr.begin()+h);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       return bs_method(arr,k, x);
}
};


