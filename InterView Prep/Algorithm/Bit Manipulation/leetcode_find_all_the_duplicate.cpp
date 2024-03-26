class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        bitset<100001>bit;
        vector<int>v;
        for(auto u:nums)
        {
            if(bit[u]) v.push_back(u);
            bit[u]=1;
        }
        return v;
        
    }
};