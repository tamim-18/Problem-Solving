class Solution {
public:
    bool canJump(vector<int>& nums) {
        int id=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]+i>=id) id=i;
        }

        return id==0;
        
    }
};