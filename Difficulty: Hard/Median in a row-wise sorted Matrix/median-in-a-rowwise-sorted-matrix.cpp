class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        // fiding the minimum and maximum element of the matrix as rows are sorted we can compare
        // the first element of each row to find the min and last element of each row to find max
        for(int i=0;i<n;i++){
            high = max(high,mat[i][m-1]);
            low = min(low,mat[i][0]);
        }
        // this is the median index for 1d array
        int desired = (n*m)/2;
        while(low<=high){
            int mid = (low+high)/2;
            int cnt = 0;
            // counnting the number of elements <=mid in each row
            for(int i=0;i<mat.size();i++){
                cnt+= upper_bound(mat[i].begin(),mat[i].end(),mid) - mat[i].begin();
            }
            // if we get the more number of elements <=mid that means median is on left side
            if(cnt>desired){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
