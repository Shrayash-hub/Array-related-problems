class Solution {
  public:
    int check(vector<int> arr,int mid){
        int sum = 0;
        int count = 1; // starting it from one because there is already a subarray
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i]; // we will addup elements to the subarray until it becomes greater than the mid
            }
            else{
                count++;
                sum=arr[i];
            }
        }
        return count;
    }
    int minTime(vector<int>& nums, int k) {
        // code here
        if(nums.size()<k) return -1;
        int ans = -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            // if count is smaller than or equal to the required number of the subarrays then we will reduce the search space, and take the mid value smaller than the before
            if(check(nums,mid)<=k){
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