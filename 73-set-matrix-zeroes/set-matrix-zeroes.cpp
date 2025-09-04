class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col1 = 1; // as cell (0,0) is overlapping after taking first row and first columns as flags.. so we will take the extra variable for the zero in first column(j=0)
        for(int i=0;i<matrix.size();i++){
            for(int j = 0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0; // first clm cells will always be type matrix[..][0]
                    if(j!=0){
                        matrix[0][j]=0; // first row cells will always be type matrix[0][..]
                    }
                    else{
                        col1 = 0;
                    }
                }
            }
        }
        // handling the elements except first row and clm
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[i].size();j++){
                if(matrix[i][j]!=0){
                    if(matrix[0][j]==0 || matrix[i][0]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        // handling the first row
        if(matrix[0][0]==0){
            for(int j=0;j<matrix[0].size();j++){
                matrix[0][j]=0;
            }
        }
        // handling the first clm
        if(col1==0){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
    }
};