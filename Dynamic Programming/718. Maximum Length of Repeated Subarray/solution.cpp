int lcs(vector<int> &text1, vector<int> &text2) {
    int max_length=0;
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
                if(max_length<dp[i+1][j+1])
                {
                    max_length = dp[i+1][j+1];
                }
            }
            else
            {
                dp[i+1][j+1] = 0;
            }
        }
    }
    return max_length;
    
}
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        return lcs(A,B);
    }
};