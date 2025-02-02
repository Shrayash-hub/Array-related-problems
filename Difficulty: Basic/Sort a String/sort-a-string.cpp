//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string sort(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << sort(s) << endl;
    
cout << "~" << "\n";
}
return 0;
}




// } Driver Code Ends


string sort(string s){
    //complete the function here
    // doing it in O(n) time complexity
    vector<int> alpha(26,0);
    string ans;
    for(int i=0;i<s.size();i++){
        alpha[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        char c = 'a'+i;
        while(alpha[i]){
            ans += c;
            alpha[i]--;
        }
    }
    return ans;
}