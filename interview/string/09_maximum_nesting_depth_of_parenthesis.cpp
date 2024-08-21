class Solution:
    def maxDepth(self, s: str) -> int:
        open,mx=0,0
        for char in s:
            if char=='(':
                open+=1
                mx=max(mx,open)
            elif char==')':
                open-=1
        return mx
        