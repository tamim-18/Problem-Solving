class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res; // Result vector to store all unique subsets
        vector<int> ans; // Temporary vector to store each subset
        sort(nums.begin(), nums.end()); // Sort the input array to handle duplicates
        solve(nums, 0, ans, res);
        return res;
    }

    void solve(vector<int>& nums, int id, vector<int>& ans, vector<vector<int>>& res) {
        res.push_back(ans); // Add the current subset to the result
        
        for (int i = id; i < nums.size(); ++i) {
            // Skip duplicates
            if (i > id && nums[i] == nums[i - 1]) continue;

            // Include the current element
            ans.push_back(nums[i]);
            solve(nums, i + 1, ans, res);

            // Exclude the current element (backtrack)
            ans.pop_back();
        }
    }
};


// time complexity O(n*2^n)
