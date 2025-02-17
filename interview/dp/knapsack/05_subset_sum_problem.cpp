class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        // initialization
        int n=arr.size();
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++){
                if(i==0) dp[i][j]=false;
                else if (j==0) dp[i][j]=true;
            }
        }
        dp[0][0]=true;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                    dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
                else 
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
};
