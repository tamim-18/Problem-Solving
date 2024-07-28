class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // Helper function to calculate the maximum amount of money that can be robbed from a linear arrangement of houses
        auto robLinear = [](vector<int>& nums, int start, int end) {
            int n = end - start + 1;
            vector<int> dp(n, 0);
            dp[0] = nums[start];
            for (int i = 1; i < n; i++) {
                int pick = nums[start + i];
                if (i > 1) pick += dp[i - 2];
                int not_pick = dp[i - 1];
                dp[i] = max(pick, not_pick);
            }
            return dp[n - 1];
        };

        // Calculate the maximum money by considering two cases:
        // 1. Excluding the last house
        // 2. Excluding the first house
        int excludeLast = robLinear(nums, 0, n - 2);
        int excludeFirst = robLinear(nums, 1, n - 1);

        return max(excludeLast, excludeFirst);
    }
};
