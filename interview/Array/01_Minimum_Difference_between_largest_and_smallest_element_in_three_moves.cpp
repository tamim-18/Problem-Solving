class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());
        int res=min(nums[n-4]-nums[0],nums[n-1]-nums[3]);
        int res2=min(nums[n-3]-nums[1],nums[n-2]-nums[2]);
        res=min(res,res2);
        return res;
       

        
    }
};

/*
The cases you are handling are:

Removing the three largest elements.
Removing the three smallest elements.
Removing the two largest elements and one smallest element.
Removing the two smallest elements and one largest element.

*/