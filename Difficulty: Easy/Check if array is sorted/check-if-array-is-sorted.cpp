class Solution {
  public:
    bool solve(vector<int> &arr,int n,int i){
        if(i+1>n-1) return true;
        if(arr[i]>arr[i+1]) return false;
        
        solve(arr,n,i+1);
    }
    bool isSorted(vector<int>& arr) {
        // code here
        // usig recursion
        int i = 0;
        return solve(arr,arr.size(),i);
    }
};