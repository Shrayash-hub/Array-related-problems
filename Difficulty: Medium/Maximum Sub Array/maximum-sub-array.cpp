// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        long long sum=0;
        int startans=-1;
        int endans=-1;
        int start =0; // to store the first index of the new array 
        int maxi=INT_MIN; 
        vector<int> ans;
        // we have to choose the best array with maximum size and the maximum sum
        for(int i=0;i<arr.size();i++){
            if(sum==0) start =i; // if sum becomes zero then we will see after the new array
            sum+=arr[i];
            if(arr[i]<0){ // if we encounter a negative number then next element to that will be the start index of new subarray
                sum=0;
                continue;
            }
            if(sum>maxi || (sum==maxi && ((i-start)>(endans-startans)))){ // (i-start)>(endans-startans) this condition is to check weather that new subarray is longer than pervious one or not
                maxi=sum;
                startans=start;
                endans = i;
            }
            if(sum<0){
                sum=0;
            }
            
        }
        if (startans == -1) return {-1};
        
        for(int i=startans;i<=endans;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};