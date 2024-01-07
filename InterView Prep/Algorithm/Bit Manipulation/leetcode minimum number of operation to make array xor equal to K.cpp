class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int n=nums.size();
        int xors=0;
        for(auto u:nums)
            xors^=u;
        int target=xors^k;
        int count=0;
        while(target>0)
        {
            count+=target&1;
            target>>=1;
            
        }
        return count;
    }
};
