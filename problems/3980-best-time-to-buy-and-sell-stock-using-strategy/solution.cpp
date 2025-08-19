class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long totalProfit = 0;

        // Computing original
        for (int i = 0; i < prices.size(); i++) {
            totalProfit += (prices[i] * strategy[i]);
        }

        long long windowSum = 0;

        long long modifiedWindowProfit = 0;
        long long modifiedWindowSum = 0;
        long long maxModifiedWindowProfit = LONG_MIN;

        for (int i = 0; i < k; i++) {
            windowSum += (prices[i] * strategy[i]);
            if (i >= k / 2)
                modifiedWindowSum += prices[i];
        }

        modifiedWindowProfit = modifiedWindowSum + (totalProfit - windowSum);
        maxModifiedWindowProfit =
            max(modifiedWindowProfit, maxModifiedWindowProfit);

        for (int i = 1; i < (strategy.size() - k + 1); i++) {

            modifiedWindowSum =
                modifiedWindowSum - (prices[i + k / 2 - 1]) + prices[i + k - 1];

            windowSum = windowSum - (prices[i - 1] * strategy[i - 1]) +
                        (prices[i + k - 1] * strategy[i + k - 1]);

            modifiedWindowProfit =
                modifiedWindowSum + (totalProfit - windowSum);
            maxModifiedWindowProfit =
                max(modifiedWindowProfit, maxModifiedWindowProfit);
        }

        return max(maxModifiedWindowProfit, totalProfit);
    }
};
