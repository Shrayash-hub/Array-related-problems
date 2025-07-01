// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int first = 0;
        int second = arr.size()-1;
        // we are using two pointer method here 
        while(first<second){
            // increasing first pointer until it reaches to 1
            if(arr[first]!=1){
                first++;
            }
            // increasing second pointer until it reaches to 0
            if(arr[second]!=0){
                second--;
            }
            // then swap them to segregate zeros and ones
            else if(arr[first]==1 && arr[second]==0){
                swap(arr[first],arr[second]);
            }
        }
    }
};