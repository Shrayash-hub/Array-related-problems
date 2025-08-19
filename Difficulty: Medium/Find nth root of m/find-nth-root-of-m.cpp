class Solution {
  public:
    int Multiples(int a,int b){
        return pow(a,b);
    }
    int nthRoot(int n, int m) {
        // Code here
        int low = 1;
        int high = m;
        while(low<=high){
            int mid = (low+high)/2;
            if(Multiples(mid,n)==m){ // if miltiples is greater than m, reduce the search space to left 
                return mid;
            }
            else if(Multiples(mid,n)>m){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
        
    }
};