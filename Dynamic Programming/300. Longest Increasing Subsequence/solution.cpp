class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> v(size,1);
        for(int i=1;i<size;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j] && v[i]<=v[j])
                {
                    v[i] = v[j]+1;
                }
            }
        }
        int max =0;
        for(int i=0;i<size;i++)
        {
            if(v[i]>max)
                max = v[i];
        }
        return max;
    }
};