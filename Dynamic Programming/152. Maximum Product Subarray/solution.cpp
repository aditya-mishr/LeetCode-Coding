class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product=nums[0];
        int pos_product=nums[0];
        int neg_product = nums[0];
        int size = nums.size();
        int temp_pos,temp_neg;
        for(int i=1;i<size;i++)
        {
            temp_pos = max({nums[i],neg_product*nums[i],pos_product*nums[i]});
            temp_neg = min({nums[i],neg_product*nums[i],pos_product*nums[i]});
            pos_product = temp_pos;
            neg_product = temp_neg;
            max_product = max({max_product,pos_product,neg_product});
        }
        return max_product;
    }
};