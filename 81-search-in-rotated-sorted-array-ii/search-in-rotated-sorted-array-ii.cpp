class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                return true;
            }
            // this condition can only create ambiguity, as we had already commpared nums[mid] with target and they are not equal so target also cannot be equal to arr[low] and arr[high] , by this fact we can reduce the search space
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;high--;
                continue;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};