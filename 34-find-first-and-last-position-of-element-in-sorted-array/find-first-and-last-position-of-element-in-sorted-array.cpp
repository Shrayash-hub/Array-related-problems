class Solution {
public:
    int FindFirst(vector<int>& arr, int x){
        int low = 0;
        int high = arr.size()-1;
        int first = -1;
        while(low<=high){
            int mid = (low + high)/2;
            if(arr[mid]==x){  // for first occurence , we have to search on the left(starting side) of the array
                first = mid;
                high = mid-1; // so we have to move left side , even if we found the target element, to find the lowest index with the target value
            }
            else if(arr[mid]<x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return first;
    }
    int FindSecond(vector<int>& arr, int x){
        int low = 0;
        int high = arr.size()-1;
        int second = -1;
        while(low<=high){
            int mid = (low + high)/2;
            if(arr[mid]==x){     // for second occurence , we have to search on the righ(ending side) of the array
                second = mid;
                low = mid+1;   // so we have to move right side , even if we found the target element, to find the highest index with the target value
            }
            else if(arr[mid]<x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return second;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = FindFirst(nums,target);
        if(first==-1) return {-1,-1};
        int second = FindSecond(nums,target);
        return {first,second};
    }
};