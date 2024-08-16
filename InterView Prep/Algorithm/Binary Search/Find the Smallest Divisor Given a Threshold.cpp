class Solution {
public:
    bool valid(vector<int>nums,int div,int t)
    {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=ceil((double)nums[i]/div);
        }
        return sum<=t;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int i;
        int mx=INT_MIN;
        for(i=0;i<n;i++)
        {
            if(nums[i]>mx)
                mx=nums[i];
            
        }
        int l=1,r=mx;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(valid(nums,mid,threshold))
            {
                r=mid-1;
            }
            else 
                l=mid+1;
        }
        return l;
        
    }
};