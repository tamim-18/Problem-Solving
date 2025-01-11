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


// meorization 
class Solution {
public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Initialize dp array with -1 to indicate uncomputed values
        vector<int> dp(n, -1);
        return solve(dp, height, n - 1, k);
    }

    int solve(vector<int>& dp, vector<int>& height, int current, int k) {
        // Base case: if we are at the first stone, cost is zero
        if (current == 0) return 0;

        // If the result is already computed, return it
        if (dp[current] != -1) return dp[current];

        int minCost = INT_MAX;

        // Iterate through all possible jumps (from 1 to k)
        for (int j = 1; j <= k; j++) {
            if (current - j >= 0) {
                int jumpCost = solve(dp, height, current - j, k) + abs(height[current] - height[current - j]);
                minCost = min(minCost, jumpCost);
            }
        }

        // Store the result in dp array and return
        return dp[current] = minCost;
    }
};
