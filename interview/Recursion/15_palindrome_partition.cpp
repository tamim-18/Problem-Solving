class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> ans;
        solve(0, ans, s);
        return res;
    }

    void solve(int id, vector<string> &ans, string &s) {
        if (id == s.size()) {
            res.push_back(ans);
            return;
        }
        for (int i = id; i < s.size(); ++i) {
            if (isPalindrome(s, id, i)) {
                ans.push_back(s.substr(id, i - id + 1));
                solve(i + 1, ans, s);
                ans.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};
