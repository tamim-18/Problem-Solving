class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto u:nums) sum+=u;
        if((sum+target)&1 or (sum+target)<0) return 0;
        int n=nums.size();
        int s=(sum+target)/2; 
        int dp[n+1][s+1];
        // now we have to count the no of subset sum=s
        for(int i=0;i<=n;i++){
            for(int j=0;j<=s;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }

        }
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=s;j++){
                if(nums[i-1]<=j) dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][s];
        
    }
};