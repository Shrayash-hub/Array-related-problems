class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        // so approch is to find the maximum element from the clm and the checking that its greater than to the elements at the left and right of it, and if we get the elements greater than to its left or right we will be reducing the search space by eliminating the clm
        while(low<=high){
            int mid = (low+high)/2;
            int maxi = INT_MIN;
            int index = -1;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>maxi){
                    maxi= mat[i][mid];
                    index = i;
                }
            }
             // if mid is at the extremes then left and right should be managed like this
            int left = (mid > 0) ? mat[index][mid-1] : -1;
            int right = (mid < m-1) ? mat[index][mid+1] : -1;
            if(maxi>left && maxi>right){
                return {index,mid};
            }
            else if(maxi<left){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {-1,-1};
    }
};