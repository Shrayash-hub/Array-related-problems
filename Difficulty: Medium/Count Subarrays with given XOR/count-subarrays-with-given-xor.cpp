class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        // this is similar to the subarray sum problem but here we will be using the property 
        // subarray XOR[i to j] = prefixXOR[j] ^ prefixXOR[i-1]
        // shifting the property k ^ prefixXOR[j] = prefixXOR[i-1]
        // we will find that there is any value available im hashmap with value currentXOR * k
        int currentXOR = 0;
        int count = 0;
        map<int,int> prefixXOR;
        for(int i=0;i<arr.size();i++){
            currentXOR ^= arr[i];
            if(currentXOR==k){
                count++;
            }
            if(prefixXOR.find(currentXOR ^ k) != prefixXOR.end()){
                count+= prefixXOR[currentXOR ^ k];
            }
            prefixXOR[currentXOR]++;
        }
        
        return count;
    }
};