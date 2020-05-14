class Solution {    
public:
    int rob(vector<int>& nums) 
    {
        int size = nums.size();
        vector<int> dp(size+2,0);
        for(int i=size-1;i>=0;i--)
        {
            dp[i] = max(nums[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
};