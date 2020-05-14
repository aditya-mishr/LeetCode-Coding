string lps(string text) {
    int index_i;
    int max_length=0;
    int size = text.size();
    int dp[size+1][size+1];
    memset(dp,0,sizeof(dp));
    for(int l=1;l<=size;l++)
    {
        for(int s=0;s<size+1-l;s++)
        {
            int e = s+l-1;
            if(text[s]==text[e])
            {
                if(s==e || s+1==e)
                    dp[s][e] = e-s+1;
                else
                {
                    if(dp[s+1][e-1]!=0)
                        dp[s][e] = 2+dp[s+1][e-1];
                    else
                        dp[s][e] = 0;
                }
                
                if(max_length<dp[s][e])
                {
                    max_length = dp[s][e];
                    index_i = e;
                }
            }
            else
                dp[s][e] = 0;
        }
    }
    string result = "";
    while(max_length!=0)
    {
        result.push_back(text[index_i]);
        max_length--;
        index_i--;
    }
    reverse(result.begin(),result.end());
    return result;
    
}
class Solution {
public:
    string longestPalindrome(string s) {
        string text1 = s;
        if(s=="")
            return s;
        return lps(text1);
    }
};