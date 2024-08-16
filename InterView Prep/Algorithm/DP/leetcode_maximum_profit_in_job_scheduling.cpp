class Solution {
public:
    int find(int i,vector<vector<int>>&job,vector<int>&startTime,int n,vector<int>& dp)
    {
        if(i>=n) return 0; //base case;
        if(dp[i]!=-1) return dp[i];
        int ind=lower_bound(startTime.begin(),startTime.end(),job[i][1])-startTime.begin();
        int pick=job[i][2]+find(ind,job,startTime,n,dp);
        int notpick=find(i+1,job,startTime,n,dp);
        return dp[i]= max(pick,notpick);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>>job;
        for(int i=0;i<n;i++)
        {
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        // for(auto &u:job)  cout<<u<<endl;
        vector<int>dp(n,-1);
        sort(job.begin(),job.end());
        sort(startTime.begin(),startTime.end());
        return find(0,job,startTime,n,dp);
    }
};
