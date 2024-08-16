class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0;
        int mn=INT_MAX;
        for(auto u:prices)
        {
            mn=min(mn,u);
            mx=max(mx,u-mn);
        }
        return mx;
        
    }
};