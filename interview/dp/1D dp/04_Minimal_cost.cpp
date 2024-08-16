class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        
        vector<int>dp(n,-1);
        return solve(dp,height,n,k);
    }
    int solve(vector<int>&dp, vector<int>&height,int n,int k){
        dp[0]=0;
        for(int i=1;i<n;i++){
            int mn=INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j>=0)
                   {
                       int  jump=dp[i-j]+abs(height[i]-height[i-j]);
                       mn=min(mn,jump);
                   }
            }
            dp[i]=mn;
        
        }
        
        return dp[n-1];
    }
};
