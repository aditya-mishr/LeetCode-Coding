int lcs(string text1, string text2) {
    int size1 = text1.size();
    int size2 = text2.size();
    int dp[size1+1][size2+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
        {
            if(text1[i]==text2[j])
            {
                dp[i+1][j+1] = 1+dp[i][j];
            }
            else
            {
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    return dp[size1][size2];
}
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text1 = s;
        reverse(s.begin(),s.end());
        return lcs(text1,s);
    }
};