class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0, bestBuy = prices[0];

        for(int i = 1; i<prices.size();i++){
            if(prices[i]>bestBuy){
                maxprofit = max(maxprofit, prices[i] - bestBuy);
            }
                bestBuy = min(bestBuy, prices[i]);

            }
            return maxprofit;
        
    }
};
