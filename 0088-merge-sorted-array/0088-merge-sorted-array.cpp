class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         // Start from the end of both arrays
    int i = m - 1; // last valid element in nums1
    int j = n - 1; // last element in nums2
    int k = m + n - 1; // position to place elements in nums1

    // Merge arrays in reverse order
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // If any elements are left in nums2, copy them
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }

    // No need to handle the case for nums1, as if i >= 0, elements are already in place.
    }
};