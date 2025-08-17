class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int high = arr.size()-1;
        int mini = INT_MAX;
        while(low<=high){
            if(arr[low]<=arr[high]){ // means array is already sorted 
                mini = min(mini, arr[low]);
                break;
            }
            int mid = low + (high - low) / 2;
            if(arr[mid]<=arr[high]){   // if arr[mid]<=arr[high] , then it means right half is sorted and we will never get mimimum on right side , because values are increasing at that side
                mini = min(mini,arr[mid]);
                high = mid-1;  // reduce search space to the left side
            }
            else{
                low = mid+1; // and if right part is not sorted than mid can be a break point so min value can be on right half
            }
        }
        return mini;
    }
};