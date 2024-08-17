class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> hash(n,0);
        vector<int> dp(n,1);

        for(int i=0; i<n; i++)
            hash[i]=i;

        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=max(dp[i], 1+dp[j]);
                    hash[i]=j;
                }
            }
        }
        int maxi=INT_MIN, ind=0;
        for(int i=0; i<n; i++){
            if(dp[i]>maxi){
                maxi=dp[i];
                ind=i;
            }
        }

        vector<int> res;
        res.push_back(nums[ind]);
        while(hash[ind]!=ind){
             res.push_back(nums[hash[ind]]);
             ind=hash[ind];
        }
        
        return res;
    }
};