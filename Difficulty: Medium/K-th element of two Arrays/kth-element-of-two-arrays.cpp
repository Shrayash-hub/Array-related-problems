class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        // for swapping the arrays so that smaller array comes first;
        if(n1>n2) return kthElement(b,a,k);
        // no of element we have to take at keft is k
        int left = k;
        // defining the range 
        int low = max(0,k-n2); // minimum number of elements from array 1 is there only when there are maximum number of elements taken from array 2
        // and maximum number of elements from array 2 is taken is by taking all the elements
        int high = min(k,n1); // max to max we can take all the elemets from array 1
        while(low<=high){
            int mid1 = (low+high)/2;
            int mid2 = left-mid1;
            // INT_MIN aur INT_MAX are taken to cover the edge case when partition is at the start or end of the array
            int l1 = INT_MIN; // left ka last element array 1 me
            int l2 = INT_MIN; // left ka last element array 2 me
            int r1 = INT_MAX; // right ka first element array 1 me
            int r2 = INT_MAX; // right ka first element array 2 me
            if(mid1<n1) r1 = a[mid1];
            if(mid2<n2) r2 = b[mid2];
            if(mid1-1>=0) l1 = a[mid1-1];
            if(mid2-1>=0) l2 = b[mid2-1];
            // now we will check the correct partition condition
            if(l1<=r2 && l2<=r1) return max(l1,l2);
            else if(l1>r2) high = mid1-1;
            else low = mid1+1;
        }
        return 0;
    }
};