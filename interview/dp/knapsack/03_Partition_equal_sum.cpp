class Solution
{
    public:
        bool canPartition(vector<int> &nums)
        {

            int sum = 0;
            for (auto u: nums) sum += u;
            if (sum & 1) return false;
            else
            {
                return can(nums, nums.size(), sum / 2);
            }
        }
    bool can(vector<int> &nums, int n, int sum)
    {
        bool dp[n + 1][sum + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j == 0) dp[i][j] = true;
                if (i == 0) dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (nums[i - 1] <= j) dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};
