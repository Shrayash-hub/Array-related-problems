class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int first = 0;
        int second = 0;
        int check[1002]={0}; // this is to put check on duplicate elements in intersection
        vector<int> arr;
        while(first<nums1.size() && second<nums2.size()){
            if(nums1[first]==nums2[second] && !check[nums1[first]]){
                arr.push_back(nums1[first]);
                check[nums1[first]]++;
                first++;
                second++;
            }
            else if(nums1[first]<nums2[second]){
                first++;
            }
            else{
                second++;
            }
        }
        return arr;
    }
};