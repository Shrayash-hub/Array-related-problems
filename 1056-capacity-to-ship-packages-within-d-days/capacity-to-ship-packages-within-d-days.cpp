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
    int sum_ele(vector<int> arr){
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        return sum;
    }
    int check(vector<int> arr,int days,int mid){
        int count = 1;
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>mid){
                sum = arr[i];
                count++;
            }
        }
        if(count<=days) return 1;
        return -1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = max_ele(weights);
        int high = sum_ele(weights);
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(weights,days,mid)==1){
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