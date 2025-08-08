class Solution {
  public:
    int merge(vector<int> &arr,int start,int mid,int end){
        int left = start;
        int right = mid+1;
        int index = 0;
        vector<int> temp(end-start+1);
        int cnt = 0;
        while(left<=mid && right<=end){
            if(arr[left]<=arr[right]){
                temp[index]=arr[left];
                index++;left++;
            }
            else{
                cnt += mid-left+1; // while merging if we get and element from left array which is greater than element of right array
                temp[index]=arr[right]; // then we will be increasing the count by mid-left+1 (all the elements at the right of that element)
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
    int inversionCount(vector<int> &arr) {
        // Code Here
        int cnt = mergeSort(arr,0,arr.size()-1);
        return cnt;
        
    }
};