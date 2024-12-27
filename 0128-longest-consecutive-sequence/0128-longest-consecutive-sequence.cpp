class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size()<1){
            return 0;
        }
        sort(arr.begin(),arr.end());
        int count = 0;
        int lastsmaller = INT_MIN; // to keep track on previous element it is in consecutive sequence or not
        int largest = 1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]-1==lastsmaller){
                count++;
                lastsmaller = arr[i];
            }
            else if(arr[i]!=lastsmaller){
                count = 1;
                lastsmaller = arr[i];
            }
            largest = max(largest , count);
        }
        return largest;
    }
};