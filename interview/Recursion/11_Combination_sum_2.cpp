class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        solve(0, res, ans, candidates, target);
        return res;
    }

    void solve(int id, vector<vector<int>>& res, vector<int>& ans, vector<int>& candidates, int target) {
        if (target == 0) {
            res.push_back(ans);
            return;
        }
        
        for (int i = id; i < candidates.size(); i++) {
            if (i > id && candidates[i] == candidates[i - 1]) {
                continue; // Skip duplicates
            }
            
            if (target >= candidates[i]) {
                ans.push_back(candidates[i]);
                solve(i + 1, res, ans, candidates, target - candidates[i]);
                ans.pop_back();
            } else {
                break; // Since the array is sorted, no need to check further
            }
        }
    }
};