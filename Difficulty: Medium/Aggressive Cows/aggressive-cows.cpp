class Solution {
  public:
    int check(vector<int> arr,int d,int k){
        if (arr.empty()) return 0;
        int pos = arr[0];
        int count = 1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]-pos>=d){
                pos = arr[i];
                count++;
                if (count >= k) return 1;
            }
        }
        return 0;
        
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        if (n == 0 || k == 0) return 0;
        
        int ans = -1;
        sort(stalls.begin(),stalls.end());
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        while(low<=high){
            int mid = (low+high)/2;
            if(check(stalls,mid,k)==1){
                low = mid+1;
                ans =mid;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};