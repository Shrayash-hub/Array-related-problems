class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> mpp;
        //firstly store all the possible values of nums1[i]+nums2[j];
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                mpp[nums1[i]+nums2[j]]++;
            }
        }
        int count =0;
        //then find , if value equals to -(nums3[k]+nums4[l]) present in the stored values
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                int target = -(nums3[i]+nums4[j]);
                if(mpp.count(target)){
                    count+=mpp[target];
                }
            }
        }
        return count;
    }
};