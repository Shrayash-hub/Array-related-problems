class Solution {
  public:
    void solve(vector<int> &arr,int n,int i){
        if(i>=n/2) return;
        swap(arr[i],arr[n-i-1]);
        solve(arr,n,i+1);
    }
    void reverseArray(vector<int> &arr) {
        // code here
        int i = 0;
        solve(arr,arr.size(),i);
    }
};