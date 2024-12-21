class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash; // store elements as key and index as value
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end()) { // hash.find(value) returns iterator to the elements 
            // if found and if not found returns hash.end()
                return {hash[complement], i};
            }
            hash[nums[i]] = i; // putting index as value and element at that index as key
        }
        // Return an empty vector if no solution is found
        return {};
    }
};
    
