//recursive tle

class Solution {
public:
    int climbStairs(int n) {
        if(n==1 or n==0) return 1;
        return climbStairs(n-1)+climbStairs(n-2);
        
    }
};

//memoization
class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
        
    }
    int solve(int n, vector<int>&dp){
        if(n==0 or n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
};

// using dp
class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
        
    }
};
//space optimized
class Solution {

public:
    int climbStairs(int n) {
        if(n==1 or n==0) return 1;
        int a=1,b=1,c;
        for(int i=2;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
