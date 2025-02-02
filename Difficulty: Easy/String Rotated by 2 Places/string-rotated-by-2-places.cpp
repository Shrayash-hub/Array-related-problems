//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    void clockWise(string &str){
        char c = str[str.size()-1];
        int index = str.size()-2;
        while(index>=0){
            str[index+1]=str[index];
            index--;
        }
        str[0]=c;
        
    }
    void anticlockWise(string &str){
        char c = str[0];
        int index = 1;
        while(index<str.size()){
            str[index-1]=str[index];
            index++;
        }
        str[str.size()-1]=c;
        
    }
    bool isRotated(string& s1, string& s2) {
        // Your code here
        if(s1.size()!=s2.size()){
            return 0;
        }
        string clockwise,anticlockwise;
        clockwise = s1;
        clockWise(clockwise);
        clockWise(clockwise);
        if(clockwise==s2){
            return true;
        }
        anticlockwise = s1;
        anticlockWise(anticlockwise);
        anticlockWise(anticlockwise);
        if(anticlockwise==s2){
            return true;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        string b;
        cin >> s >> b;
        cin.ignore();
        Solution obj;
        cout << (obj.isRotated(s, b) == 0 ? "false" : "true") << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends