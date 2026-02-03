class Solution {
  public:
    bool solve(string &s,int n,int i){
        // base case ->when pointer will pass the middle
        if(i>=n/2) return true;
        // we are going to match elements from start and last 
        // i = 1 then n-i-1 is going to give first element from last
        if(s[i]!=s[n-i-1]) return false;
        
        // recursive call
        solve(s,n,i+1);
    }
    bool isPalindrome(string& s) {
        // code here
        int i = 0;
        return solve(s,s.size(),i);
    }
};