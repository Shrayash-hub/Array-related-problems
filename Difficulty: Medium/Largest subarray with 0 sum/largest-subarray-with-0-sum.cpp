class Solution {
  public:
    int maxLength(vector<int>& arr) {
        //so the intution is we will be finding the two subarray with the same prefix sum , and the portion
        // between those two subarray will have sum=0;
        map<long long,int> mpp;
        long long sum=0;
        int maxlen= 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(sum==0){
                maxlen = max(maxlen,i+1); // if we found a subarray with sum zero that can be the longest subarray also
            }
            if(mpp.find(sum)!=mpp.end()){
                maxlen = max(maxlen,i-mpp[sum]); // if the subarray with the same prefix sum is found 
            }
            if(mpp.find(sum)==mpp.end()){
                mpp[sum] = i;           // if not then we will update the key value pair;
            }
        }
        return maxlen;
        
    }
};