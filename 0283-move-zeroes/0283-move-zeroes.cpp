class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros=0,n=nums.size();
    
    if(nums[0]==0){
            nums.erase(nums.begin());
        }
    for(int i=0;i<nums.size();i++){
        
        if(nums[i]==0){
            nums.erase(nums.begin()+i);
            i--;
        }
    }
    nums.resize(n);
   
    
    }
};