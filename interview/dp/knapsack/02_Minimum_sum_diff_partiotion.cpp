class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=arr[i];
	    bool dp[n+1][sum+1];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=sum;j++) 
	            {
	                if(i==0) dp[i][j]=false;
	                if(j==0) dp[i][j]=true;
	            }
	    }
	    dp[0][0]=true;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1]<=j){
	                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
	            }
	            else {
	                dp[i][j]=dp[i-1][j];
	            }
	            
	        }
	    }
	    int ans=INT_MAX;
	    // checking the last row of the table;;
	    for(int i=sum/2;i>=0;i--){
	        if(dp[n][i])
	            ans=min(ans,abs(sum-2*i));
	            
	    }
	    
	    return ans;
	} 
};
