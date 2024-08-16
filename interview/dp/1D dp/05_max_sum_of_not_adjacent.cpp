// memorization

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>dp(n,-1);
        return solve(arr,n-1,dp);
    }
    int solve(int arr[],int idx,vector<int>&dp){
        //base case
        if(idx==0) return arr[idx];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick=arr[idx]+solve(arr,idx-2,dp);
        int not_pick=0+solve(arr,idx-1,dp);
        dp[idx]=max(pick,not_pick);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)

// using tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0, prev = nums[0];

        for(int i=1; i<n; i++) {
            int curr = max(nums[i]+prev2, prev);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)

// using space optimized tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0, prev = nums[0];

        for(int i=1; i<n; i++) {
            int curr = max(nums[i]+prev2, prev);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)