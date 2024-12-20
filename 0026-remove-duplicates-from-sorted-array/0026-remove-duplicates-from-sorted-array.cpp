class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Brute force approch is taking an empty set and try to put the elements of array in it
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};