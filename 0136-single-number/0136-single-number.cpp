class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // a ^ a = 0 and 0 ^ a = a;
        int num = 0;
        for(int i=0;i<nums.size();i++){
            num^=nums[i];
        }

        return num;
    }
};