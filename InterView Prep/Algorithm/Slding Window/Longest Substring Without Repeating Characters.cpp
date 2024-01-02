 class Solution {

public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        int l=0,r=0;
        bool vis[256]={false};
        int mx=INT_MIN;
        while(r<n)
        {
            if(vis[s[r]])
            {
                while(vis[s[r]])
                {
                    vis[s[l++]]=false;
                    

                }
            }
            mx=max(mx,r-l+1);
            vis[s[r++]]=true;
        }
        return mx;
        
    }
      
  
};