class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int>ans;
        solve(0,res,ans,target,candidates);
        return res;
        
    }
    void solve(int id, vector<vector<int>>&res, vector<int>&ans,int target,vector<int>&nums){
        if(id==nums.size()) {
            if(target==0) res.push_back(ans);
            return;
        }
        //take
       if(target>=nums[id]){
        ans.push_back(nums[id]);
        solve(id,res,ans,target-nums[id],nums);
        ans.pop_back();
       }
       // not take
       solve(id+1,res,ans,target,nums);
    }
};