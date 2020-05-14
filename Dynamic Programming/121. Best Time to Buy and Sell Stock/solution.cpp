class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int len=prices.size();
        int max_element=prices[len-1];
        int max_profit=0;
        int profit;
        for(int i=len-2;i>=0;i--)
        {
            profit = max_element-prices[i];
            if(profit>max_profit)
                max_profit=profit;
            if(prices[i]>max_element)
                max_element = prices[i];
        }
        return max_profit;
    }
};