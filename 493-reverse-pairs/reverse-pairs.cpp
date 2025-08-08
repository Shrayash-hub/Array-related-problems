class Solution {
public:
    int merge(vector<int> &arr,int start,int mid,int end){
        int left = start;
        int right = mid+1;
        int index = 0;
        vector<int> temp(end-start+1);
        int cnt = 0;
        int j = mid + 1;
        // we will be using two pointer approch and going to count the elements 
        for (int i = start; i <= mid; i++) {
            while (j <= end && (long long)arr[i] > 2LL * arr[j]) j++;
            cnt += (j - (mid + 1));
        }
        while(left<=mid && right<=end){
            if(arr[left]<=arr[right]){
                temp[index]=arr[left];
                index++;left++;
            }
            else{
                temp[index]=arr[right]; 
                index++;right++;
            }
        }
        while(left<=mid){
            temp[index]=arr[left];
            index++;left++;
        }
        while(right<=end){
            temp[index]=arr[right];
            index++;right++;
        }
        index = 0;
        for(int i=start;i<=end;i++){
            arr[i] = temp[i-start];
        }
        return cnt;
    }
    int mergeSort(vector<int> &arr,int l,int r){
        int cnt = 0;
        if(r<=l) return cnt;
        int mid = (l+r)/2;
        cnt += mergeSort(arr,l,mid);
        cnt += mergeSort(arr,mid+1,r);
        cnt += merge(arr,l,mid,r);
        return cnt;
        
    }
    int reversePairs(vector<int>& nums) {
        int cnt = mergeSort(nums,0,nums.size()-1);
        return cnt;
    }
};