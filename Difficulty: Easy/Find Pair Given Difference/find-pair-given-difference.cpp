
class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < arr.size(); i++) {
            int complement1 = arr[i] - x;
            int complement2 = arr[i] + x;

            if (mpp.find(complement1) != mpp.end() || 
                mpp.find(complement2) != mpp.end()) {
                return true;
            }
            mpp[arr[i]] = i;
        }
        return false;
    }
};
