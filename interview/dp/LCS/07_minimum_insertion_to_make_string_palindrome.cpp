class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        string x=s;
        reverse(s.begin(),s.end());
        return n-lps(x,s,n);
        
    }
    int lps(string x,string y,int n){
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++) {
                if(i==0 or j==0) dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][n];
    }
};
