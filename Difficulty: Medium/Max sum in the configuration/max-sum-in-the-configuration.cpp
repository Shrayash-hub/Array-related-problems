class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int sum = 0;
        int sum1 = 0;
        for(int i=0;i<arr.size();i++){
            sum+= arr[i];
            sum1+= i*arr[i];
        }
        int maxi = sum1;
        for(int i=1;i<arr.size();i++){
            int currSum = sum1-sum+arr.size()*arr[i-1];
            maxi = max(maxi,currSum);
            sum1 = currSum;
        }
        return maxi;
    }
};