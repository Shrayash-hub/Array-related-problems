// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &mat) {
        // code here
        int max_count = -1;
        int index = -1;
        for(int i=0;i<mat.size();i++){
            // we can find the first index of the 1 and then subtract it from the clm size , to find the count of the 1's
            auto it = lower_bound(mat[i].begin(), mat[i].end(), 1);
        
            // Distance nikal lo
            int count = mat[i].end() - it; // Number of 1's in this row
            if(count>max_count) {
                max_count = count;
                index = i;
            }
        }
        return index;
    }
};