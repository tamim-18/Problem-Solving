class Solution {
public:
    int countSubsets(vector<int>& nums, int k) {
        int count = 0;
        int currentSum = 0;
        solve(0, currentSum, nums, k, count);
        return count;
    }

    void solve(int id, int currentSum, vector<int>& nums, int k, int& count) {
        if (id == nums.size()) {
            if (currentSum == k) {
                count++; // Increment the count if the subset sum equals k
            }
            return;
        }

        // Include the current element in the subset
        solve(id + 1, currentSum + nums[id], nums, k, count);

        // Do not include the current element in the subset
        solve(id + 1, currentSum, nums, k, count);
    }
};
