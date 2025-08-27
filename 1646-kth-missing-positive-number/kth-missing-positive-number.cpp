class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            // as original array should be like [1,2,3,4,5...] , so we can find number of missing elements by this formula
            int missing = arr[mid]-(mid+1); // we have to find number of missing element till that index and if it is smaller than k then we have to move forward
            if(missing<k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        // we cant directly return arr[high]+(k-missing), because in some cases high can be -1 , so we have to derive a formula
        // we have arr[high] + more and more = (k-missing)
        // arr[high] + (k-missing) and missing = arr[high]-(high+1)
        // arr[high] + k - arr[high] +high +1
        // k + high + 1; --> this can also be answer
        // low = high + 1
        // low + k
        return low+k;
    }
};