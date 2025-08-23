class Solution {
public:
    int max_ele(vector<int> arr){
        int maxi = INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxi){
                maxi = arr[i];
            }
        }
        return maxi;
    }
    int min_ele(vector<int> arr){
        int mini = INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<mini){
                mini = arr[i];
            }
        }
        return mini;
    }
    int check(int mid,vector<int> arr,int m,int k){
        int count = 0;
        int bouq = 0;
        for(int i =0;i<arr.size();i++){
            if(arr[i]<=mid){
                count++;
                if(count==k) {
                    bouq++ ;
                    count=0 ;
                }
            }
            else{
                count=0;
            }
        }
        if(bouq>=m) return 1;
        return 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       if(1LL*m*k > bloomDay.size()) return -1; 
       int low = min_ele(bloomDay); 
       int high = max_ele(bloomDay); 
       int ans = -1;
       while(low<=high){
        int mid = (low+high)/2;
        if(check(mid,bloomDay,m,k)==1){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
       }
       return ans;
    }
};