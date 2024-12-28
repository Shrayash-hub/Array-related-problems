class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size()<1){
            return 0;
        }
        int largest =1;
        unordered_set<int> s;
        for(int i=0;i<arr.size();i++){
            s.insert(arr[i]);
        }
        for(auto it: s){
           if(s.find(it-1)==s.end()){
                int count=1;
                int x = it;
                while(s.find(x+1)!=s.end()){
                    x=x+1;
                    count++;
                }
                largest = max(largest,count);
           }
            
        }
        return largest;
    }
};