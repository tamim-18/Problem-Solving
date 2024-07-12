class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if (x > y) {
            ans += removeSubstrings(s, "ab", x);
            ans += removeSubstrings(s, "ba", y);
        } else {
            ans += removeSubstrings(s, "ba", y);
            ans += removeSubstrings(s, "ab", x);
        }
        return ans;
    }

private:
    int removeSubstrings(string &s, const string &pattern, int points) {
        int score = 0;
        string result;
        for (char c : s) {
            if (!result.empty() && result.back() == pattern[0] && c == pattern[1]) {
                result.pop_back();
                score += points;
            } else {
                result.push_back(c);
            }
        }
        s = result;
        return score;
    }
};
