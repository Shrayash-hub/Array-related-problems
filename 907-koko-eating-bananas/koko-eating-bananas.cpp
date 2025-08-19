class Solution {
public:
int maxElement(vector<int> arr){
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxi){
                maxi = arr[i];
            }
        }
        return maxi;
    }
    long long TimeRequired(vector<int> arr,int mid){
        long long time = 0;
        for(int i=0;i<arr.size();i++){
            time += ceil((double)arr[i]/(double)mid);
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxElement(piles);
        int ans;
        while(low<=high){
            int mid = (low+high)/2;
            long long totalhrs = TimeRequired(piles,mid);
            if(totalhrs<=h){ // if totalhrs are smaller than h that means mid speed is working , now we have to try some smaller speed
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