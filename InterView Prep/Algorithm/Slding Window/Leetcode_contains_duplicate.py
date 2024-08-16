class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        l=0;
        window=set()
        r=0;
        n=len(nums)
        while r<n:
            if r-l>k:
                window.remove(nums[l])
                l+=1
            if nums[r] in window:
                return True
            window.add(nums[r])
            r+=1
        return False;
        