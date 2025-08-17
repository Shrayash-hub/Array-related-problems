class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int low = 0;
        int high = arr.size()-1;
        int index;
        int ans= INT_MAX;
        // no. of rotation = index of minimum element
        while(low<=high){
            if(arr[low]<=arr[high]){
                if(arr[low]<ans){   // check that arr[low] is minimum or not
                    index = low;
                    ans = arr[low];
                }
                break;
            }
            int mid = (low+high)/2;
            if(arr[low]<=arr[mid]){
                if(arr[low]<ans){
                    ans = arr[low];
                    index = low;
                }
                low = mid+1;
            }
            else{
                if(arr[mid]<ans){
                    ans = arr[mid];
                    index = mid;
                }
                high = mid-1;
                }
            }
            return index;
        }
    
};
