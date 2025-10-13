
// T.C = 0(n)
//S.C = 0(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0;        // To store the maximum profit found so far
        int bestBuy = prices[0];  // Initialize the best (lowest) buying price as the first day's price

        // Loop through the prices starting from the second day
        for (int i = 1; i < prices.size(); i++) {

            // If the current price is greater than the bestBuy, 
            // calculate the profit and update maxProfit if it's higher
            if (prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }

            // Update the bestBuy price if a lower price is found
            bestBuy = min(bestBuy, prices[i]);
        }

        // Return the maximum profit possible
        return maxProfit;
    }
};