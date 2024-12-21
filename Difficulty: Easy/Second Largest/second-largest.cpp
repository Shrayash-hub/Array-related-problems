//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        if(arr.size() < 2) return INT_MIN;
    
    // First find the largest element
        int largest = arr[0];
    
        bool allEqual = true;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] != arr[0]) {
                allEqual = false;
            }
            if(arr[i] > largest) {
                largest = arr[i];
            }
        }
    
    // If all elements are equal, no second largest exists
        if(allEqual) {
            return -1;  // or INT_MIN, depending on your requirement
        }
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > largest) {
                largest = arr[i];
            }
        }
    
    // Now find the largest element strictly less than largest
        int sec_largest = INT_MIN;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != largest && arr[i] > sec_largest) {
                sec_largest = arr[i];
            }
        }
    
        return sec_largest;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends