class Solution
{
    public:
        string frequencySort(string s)
        {

            unordered_map<char, int> freq;
            for (auto u: s) freq[u]++;
            vector<pair<char, int>> v(freq.begin(), freq.end());
            sort(v.begin(), v.end(), cmp);
            string res;
            for (auto u: v) res.append(u.second, u.first);
            return res;
        }
    static bool cmp(pair<char, int> a, pair<char, int> b)
    {
        return a.second > b.second;
    }
};