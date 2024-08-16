class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1,-1);
        return solve(n-1,dp,height);
    }
    
    int solve(int n,vector<int>&dp, vector<int>&height){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int right=INT_MAX;
        int left=solve(n-1,dp,height)+abs(height[n-1]-height[n]);
        if(n>1)
             right=solve(n-2,dp,height)+abs(height[n-2]-height[n]);
        return dp[n]=min(left,right);
    }
};

// matrix approach

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(n-1,0,dp,height);
    }
    
    int solve(int n,int flag,vector<vector<int>>&dp, vector<int>&height){
        if(n==0) return 0;
        if(dp[n][flag]!=-1) return dp[n][flag];
        int right=INT_MAX;
        int left=solve(n-1,0,dp,height)+abs(height[n-1]-height[n]);
        if(n>1)
             right=solve(n-2,1,dp,height)+abs(height[n-2]-height[n]);
        return dp[n][flag]=min(left,right);
    }
};