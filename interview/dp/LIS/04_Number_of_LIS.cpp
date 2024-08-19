class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        int mx=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[i]<1+dp[j] and nums[j]<nums[i]){
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                }
                else if(nums[i]>nums[j] and dp[i]==1+dp[j])
                {
                    cnt[i]+=cnt[j];
                } 
            }
            if(dp[i]>mx) mx=dp[i];
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(dp[i]==mx) res+=cnt[i];
        }

        return res;

        
    }
};
