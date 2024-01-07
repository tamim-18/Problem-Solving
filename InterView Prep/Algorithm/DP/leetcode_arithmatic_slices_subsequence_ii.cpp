class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        unordered_map<long,int>dp[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long diff=(long)nums[i]-nums[j];
                auto it=dp[j].find(diff);
                int cntJ=it==end(dp[j])?0:it->second;
                dp[i][diff]+=cntJ+1;
                result+=cntJ;
            }
        }
        return result;
        
    }
};
