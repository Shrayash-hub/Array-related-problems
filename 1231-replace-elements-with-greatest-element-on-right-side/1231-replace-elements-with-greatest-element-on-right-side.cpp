class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        
        
        if(n<2){
            arr[0]=-1;
            return arr;
        }
        int max = -1;
        for(int i=n-1;i>=0;i--){
            
            if(arr[i]>max){
                max = arr[i];
            }
            arr[i]=max;
           
        }
        arr.push_back(-1);
        arr.erase(arr.begin());
        return arr;
    }
};