class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0)
            return 0;
        int m = matrix[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        int max_area=0;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]=='1')
            {
                dp[i][0] = 1;
                if(max_area<dp[i][0])
                    max_area = dp[i][0];
            }
        }
        for(int j=0;j<m;j++)
        {
            if(matrix[0][j]=='1')
            {
                dp[0][j] = 1;
                if(max_area<dp[0][j])
                    max_area = dp[0][j];
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    dp[i][j] = 1+min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]});
                    if(max_area<dp[i][j])
                    max_area = dp[i][j];
                    
                }
            }
        }
        
        return max_area * max_area;
    }
};