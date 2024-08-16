class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        l,m,h=0,0,n-1
        # print(h)
        while m<=h:
            if nums[m]==0:
                nums[l],nums[m]=nums[m],nums[l]
                l=l+1
                m=m+1
            elif nums[m]==1:
                m=m+1
            else:
                nums[m], nums[h] = nums[h], nums[m]
                h=h-1

        