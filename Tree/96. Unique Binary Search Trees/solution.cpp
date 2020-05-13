class Solution {
public:
    int numTrees(int n) {
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(1);
        if(n==0||n==1)
            return 1;
        int bst = 0;
        for(int i=2;i<=n;i++)
        {
            bst=0;
            for(int j=0;j<i;j++)
                bst +=dp[j]*dp[i-1-j];
            dp.push_back(bst);
        }
        return dp[n];
        
    }
};