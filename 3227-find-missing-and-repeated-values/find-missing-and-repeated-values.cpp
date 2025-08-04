class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;

        vector<int> freq(total+1, 0); // for the 1-based indexing
        vector<int> ans(2, -1);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                freq[grid[i][j]]++;
            }
        }

        for(int num=1; num<=total; num++){
            if(freq[num] == 2) ans[0] = num;  // repeated
            if(freq[num] == 0) ans[1] = num;  // missing
        }

        return ans;
    }
};