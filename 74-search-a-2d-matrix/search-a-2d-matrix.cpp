class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int high = n*m-1;
        while(low<=high){
            int mid = (low+high)/2;
            // formula to convert the 1D array index into 2D array coordinates
            int row = mid/m;
            int clm = mid%m;
            if(matrix[row][clm]==target) return true;
            else if(matrix[row][clm]<target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};