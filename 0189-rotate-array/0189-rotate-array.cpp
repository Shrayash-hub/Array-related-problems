class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*this is the brute force approch
        int j=0;
        while(k>0){
            int out=nums[nums.size()-1];
            for(int i=nums.size()-1;i>0;i--){
                
                nums[i]=nums[i-1];
            }
            nums[0]=out;
            k--;j--;
        }
        for(auto it: nums){
            cout<<it;
        }*/ 
        int n =nums.size(),arr[n];
        if (n <= 1)
        return;
        k = k % n;
        if (k > n)
        return;
        
        //store the elements that are going to out of the array
        for(int i=n-k;i<n;i++){
            arr[i-(n-k)]=nums[i];
        }
        //now start shifting the elements
        for(int i=n-1;i>=k;i--){
            nums[i]=nums[i-k];
        }
        //now copy the stored element to the array
        for(int i=0;i<=k-1;i++){
            nums[i]=arr[i];
        }
        //print the vector
        for(auto it: nums){
            cout<<it;
        }
    }
};