// User function Template for C++
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int low = 0;
        int high = arr.size()-1;
        int ans = arr.size();
        while(low<=high){
            int mid = low + (high-low)/2;
            // upper bound of a number is defined as the smallest index in the 
            //sorted array where the element is strictly greater than the given number.
            if(arr[mid]>target){ // so arr[mid]>target
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
