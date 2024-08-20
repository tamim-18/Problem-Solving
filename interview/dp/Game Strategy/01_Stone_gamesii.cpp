class Solution {
public:
    int dp[2][101][101];
    int stoneGameII(vector<int>& piles) {

        // strategy for game theory
        // do best for your turn
        // expect worst from your opponent
        memset(dp,-1,sizeof(dp));
        return solve(piles,1,0,1);

        
        
    }

    int solve(vector<int>&piles,int person,int i,int M)
    {
        // base case 
        int n=piles.size();
        if(i>=n) return 0;
        // check for overlapping subproblem
        if(dp[person][i][M]!=-1) return dp[person][i][M];
        int sum=0;
        int result=(person==1)?-1:INT_MAX;
        for(int x=1;x<=min(2*M,n-i);x++){
            sum+=piles[i+x-1];
            if(person==1){
                // alice turn
                result=max(result,sum+solve(piles,0,i+x,max(M,x)));
            }else{
                // bob turn
                result=min(result,solve(piles,1,i+x,max(M,x)));
            }

        } 
        return dp[person][i][M]=result;
    }
};