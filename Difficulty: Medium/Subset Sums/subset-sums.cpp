class Solution {
  public:
    void subsetSum(int index, vector<int>& arr, vector<int>& ans, int sum) {
        // BASE CASE
        if (index == arr.size()) {
            ans.push_back(sum);
            return;
        }

        // PICK the current element
        subsetSum(index + 1, arr, ans, sum + arr[index]);

        // NOT PICK the current element
        subsetSum(index + 1, arr, ans, sum);
    }

    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        subsetSum(0, arr, ans, 0);
        return ans;
    }
};