class Solution {
  public:
    long long int count(int coins[], int n, int amount) {

        // code here.
        long long  dp[n+1][amount+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j) dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        // cout<<dp[n][amount];
        return dp[n][amount];
        

        
    }
};