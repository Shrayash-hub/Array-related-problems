class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int clm = matrix[0].size()-1;
        // matrix is sorted in this order  0 _ _ _ _ _(m-1)
        //                                            |
        //                                            |
        //                                            |
        //                                            v(n-1)
        while(row<matrix.size() && clm >= 0){
            if(matrix[row][clm]==target){
                return true;
            }
            else if(matrix[row][clm]<target){
                row++;
            }
            else clm--;
        }
        return false;
    }
};