class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        int no_coin = coins.size();
        vector<int> dp(n+1,1000000);
        dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j = 0;j<no_coin;j++)
            {
                if(i-coins[j]>=0 && dp[i-coins[j]]>=0)
                dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }
            if(dp[i]==1000000)
                dp[i] =-1;
            
        }
        // for(int i=0;i<n+1;i++)
        //         cout<<dp[i]<<" ";
        return dp[n];
    }
};