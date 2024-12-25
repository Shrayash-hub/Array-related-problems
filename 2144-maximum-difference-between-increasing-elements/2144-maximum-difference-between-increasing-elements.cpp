class Solution {
public:
    int maximumDifference(vector<int>& arr) {
        int max_diff = arr[1] - arr[0];
        int min_ele = arr[0];
        for(int i=1;i<arr.size();i++){
            int diff = arr[i]-min_ele;
            max_diff = max(max_diff,diff);
            min_ele = min(min_ele,arr[i]);
        }
        if(max_diff<=0){
            return -1;
        }
        return max_diff;
    }
};