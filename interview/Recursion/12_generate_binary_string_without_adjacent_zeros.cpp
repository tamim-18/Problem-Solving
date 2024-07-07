class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        string ans = "";
        solve(ans, res, n);
        return res;
    }

    void solve(string ans, vector<string>& res, int n) {
        // Base case
        if (ans.size() == n) {
            res.push_back(ans);
            return;
        }
        // Recursive case
        if (ans.empty() || ans.back() != '0') solve(ans + '0', res, n);
        solve(ans + '1', res, n);
    }
};
