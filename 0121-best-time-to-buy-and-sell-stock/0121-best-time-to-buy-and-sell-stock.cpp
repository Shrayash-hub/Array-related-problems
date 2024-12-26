class Solution {
public:
    int maxProfit(vector<int>& price) {
        int cost = price[0];
        int profit = 0;
        for(int i=0;i<price.size();i++){
            int profitnew = price[i]-cost;
            profit = max(profitnew,profit);
            cost = min(cost,price[i]);
        }
        return profit;
    }
};