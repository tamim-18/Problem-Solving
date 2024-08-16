class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int>ans;

        solve(nums,0,ans);
        return res;
        
    }
    void solve(vector<int>&nums,int id,vector<int>&ans)
    {
        if(id==nums.size()){
            res.push_back(ans);
            return;
        }
        //take..
        ans.push_back(nums[id]);
        solve(nums,id+1,ans);
        /// don't take
        ans.pop_back();
        solve(nums,id+1,ans);
    }

};