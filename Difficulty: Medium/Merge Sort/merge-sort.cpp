class Solution {
  public:
    void merge(vector<int> &arr, int start, int mid, int end){
        // we will be using an temp array in which we will be merging the arrays
        vector<int> temp(end-start+1);
        int left = start;   // left can range from start to mid
        int right = mid+1;  // right can range from mid+1 to end
        int index =0;  
        while(left<=mid && right<=end){
            if(arr[left]<=arr[right]){  // if element from left side is smaller than element from right side
                temp[index]=arr[left];
                left++;index++;
            }
            else{
                temp[index]=arr[right];
                index++;right++;
            }
        }
        while(left<=mid){             // when some element are still remain in left array as both the arrays are not of equal size
                temp[index]=arr[left];
                index++;left++;
            }
        while(right<=end){            // similarily if element are left in right array
            temp[index]=arr[right];
            index++;right++;
        }
        index=0;
        while(start<=end){            // placing each element of temp into the original array
            arr[start]=temp[index];
            start++;index++;
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r) return; // array of size 1, base condition
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);  // for the first half of the array
        mergeSort(arr,mid+1,r); // for the second half of the array
        merge(arr,l,mid,r);   // merging the arrays
        
    }
};