class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int count1=0;
        int count2=INT_MIN;
        while(start<n){
            if(nums[start]!=0){
                count1++;
            }
            else{
                if(count1>count2){
                    count2=count1;
                }
                count1=0;
            }
            if(start==n-1){
                if(count1>count2){
                    count2=count1;
                }
            }
            start++;
        }
        return count2;

    }
};