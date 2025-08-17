class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       if(nums.size()==1) return nums[0];
       // handling the edge cases of first and last element separately
       if(nums[0]!=nums[1]) return nums[0];
       if(nums[nums.size()-2]!=nums[nums.size()-1]) return nums[nums.size()-1];
       // using the fact that before the single element the pair are the format of (even,odd) indexs and after the single element the pairs are in the (odd,even) format
       int low = 1;
       int high = nums.size()-2;
       while(low<=high){
        int mid = (low+high)/2;
        // element which doest match the element before it and element after is single element
        if(nums[mid-1]!=nums[mid] && nums[mid]!= nums[mid+1]){
            return nums[mid];
        }
        // for the left side (even,odd format) , if mid is even then element after it will be similar(at odd index) and if mid is odd element before it will be similar(at even index)
        if(mid%2==0 && nums[mid]==nums[mid+1] || (mid%2!=0 && nums[mid-1]==nums[mid])){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
       }
       return -1; 
    }
};