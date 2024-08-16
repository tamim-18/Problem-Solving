class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<amount+1;j++){
                if(i==0) dp[i][j]=INT_MAX-1;
                if(i!=0 and j==0) dp[i][j]=0;
                if(i==1){
                    if(j%coins[0]==0) dp[i][j]=j/coins[0];
                    else dp[i][j]=INT_MAX-1;
                }
            }
        }
        // unbounded knapsack
        for(int i=2;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j) dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]); //why int_max-1 . beacue of it
                else dp[i][j]=dp[i-1][j];
            }
        }
        if(dp[n][amount]==INT_MAX-1) return -1;
        return dp[n][amount];
        
    }
};