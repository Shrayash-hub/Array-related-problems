//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int> unions;
        int p1=0;
        int p2=0;
        while(p1<a.size() && p2<b.size()){
            if(a[p1]==b[p2]){
                if(unions.empty() || unions.back() != a[p1]){
                unions.push_back(a[p1]);
                }
                p1++;
                p2++;
            }
            else if(a[p1]<b[p2]){
                if(unions.empty() || unions.back() != a[p1]){
                unions.push_back(a[p1]);
                }
                p1++;
            }
            else if(a[p1]>b[p2]){
                if(unions.empty() || unions.back() != b[p2]){
                unions.push_back(b[p2]);
                }
                p2++;
            }
        }
        while(p1<a.size()){
            if(unions.empty() || unions.back() != a[p1])
            {
            unions.push_back(a[p1]);
            }
            p1++;
        }
        while(p2<b.size()){
            if(unions.empty() || unions.back() != b[p2])
            {
            unions.push_back(b[p2]);
            }
            p2++;
        }
        return unions;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends