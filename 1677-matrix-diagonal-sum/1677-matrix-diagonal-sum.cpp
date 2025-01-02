class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum =0;
        for(int i=0;i<n;i++){
            sum += mat[i][i];
        }
        int i = 0; int j = n-1;
        while(j>=0){
            sum+= mat[i][j];
            i++;j--;
        }
        if(n%2==0){
            return sum;
        }
        return sum - mat[n/2][n/2];
    }
};