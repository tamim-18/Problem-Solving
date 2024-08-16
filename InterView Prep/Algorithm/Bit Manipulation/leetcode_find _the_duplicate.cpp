class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        bitset<100001>bit;
        for(auto u:nums) {
            if(bit[u]) return u;
            bit[u]=1;
        }
        return 0;
    }
};