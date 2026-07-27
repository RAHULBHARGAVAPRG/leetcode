class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size()-1;
        long long prod=(nums[n]-1)*(nums[n-1]-1);
        return prod;

        
    }
};