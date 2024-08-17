// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n,vector<int>(n+1,-1));
//         return f(0,-1,nums,dp);
        
//     }
//     int f(int id,int prev,vector<int>& nums,vector<vector<int>>&dp){
//         if(id==nums.size()) return 0;
//         if(dp[id][prev+1]!=-1)  return dp[id][prev+1];
//         // not take
//         int len=f(id+1,prev,nums,dp);
//         if(prev==-1 or nums[id]>nums[prev]) len=max(len,1+f(id+1,id,nums,dp));

//         return dp[id][prev+1]=len;

//     }
// };


// tabulation

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 1);  // Initialize dp array with 1 since the minimum length of LIS is 1
        
//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[i] > nums[j]) {
//                     dp[i] = max(dp[i], dp[j] + 1);  // Update dp[i] if nums[i] can extend the subsequence ending at nums[j]
//                 }
//             }
//         }
        
//         return *max_element(dp.begin(), dp.end());  // The answer is the maximum value in dp array
//     }
// };


/*

    Printing LIS
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);  // Length of LIS ending at each element
        vector<int> parent(n, -1);  // To keep track of the previous element in the LIS
        int maxLen = 1, lastIndex = 0;  // To track the length and end index of the LIS
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;  // Update the parent index
                }
            }
            // Update maximum length and last index of LIS
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // To print the LIS, reconstruct the sequence using the parent array
        vector<int> lis;
        for (int i = lastIndex; i >= 0; i = parent[i]) {
            lis.push_back(nums[i]);
            if (parent[i] == -1) break;
        }
        reverse(lis.begin(), lis.end());  // The sequence was reconstructed backwards

        // Print the LIS
        cout << "The Longest Increasing Subsequence is: ";
        for (int num : lis) {
            cout << num << " ";
        }
        cout << endl;

        return maxLen;  // Return the length of the LIS
    }
};
