class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());      // O(n log n)
        vector<vector<int>> ans;
        int i = 0;

        while(i < intervals.size()){
            // we will put a track of starting and ending index and updating it      according to our condtion
            int start = intervals[i][0];
            int end = intervals[i][1];

            while(i + 1 < intervals.size() && end >= intervals[i+1][0]){
                end = max(end, intervals[i+1][1]);
                i++;
            }

            ans.push_back({start, end});
            i++;
        }
        return ans;
    }
};