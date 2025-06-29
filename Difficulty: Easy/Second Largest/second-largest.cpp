class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        // checking if all element are equal
        bool allequal = true;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]!=arr[i+1]){
                allequal = false;
            }
        }
        if(allequal) return -1;
        
        // firstly we are going to take two variables 
        int largest = arr[0];
        int second_largest = INT_MIN;
        // now we will be comparing largest with the each element of the array
        for(int i=1;i<arr.size();i++){
            // if element is greater than largest then then we will be updating the largest with that 
            // element and second largest will be the previous value of the largest 
            if(arr[i]>largest){
                second_largest = largest;
                largest = arr[i];
            }
            // in case we get a element with is smaller than largest and greater than second largest then it will 
            // be the second largest element
            else if(arr[i]>second_largest && arr[i]<largest){
                second_largest = arr[i];
            }
        }
        return second_largest;
    }
};