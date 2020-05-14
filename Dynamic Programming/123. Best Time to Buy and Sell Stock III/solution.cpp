class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> first;
        vector<int> second;
        int size = prices.size();
        if(size==0)
            return 0;
        int min = prices[0];
        first.push_back(0);
        int profit;
        int max_pro=0;
        for(int i=1;i<size;i++)
        {
            profit = prices[i]-min;
            if(min>prices[i])
                min = prices[i];
            if(profit>max_pro)
                max_pro = profit;
            first.push_back(max_pro);
        }
        int max =prices[size-1];
        second.push_back(0);
        profit=0;
        max_pro=0;
        for(int i=size-2;i>=0;i--)
        {
            profit = max-prices[i];
            if(max<prices[i])
                max = prices[i];
            if(profit>max_pro)
                max_pro = profit;
            second.push_back(max_pro);
            
        }
        reverse(second.begin(),second.end());
        int max_profit=0;
        for(int i=0;i<size;i++)
        {
            if(first[i]+second[i]>max_profit)
                max_profit = first[i]+second[i];
        }
        return max_profit;
    }
};