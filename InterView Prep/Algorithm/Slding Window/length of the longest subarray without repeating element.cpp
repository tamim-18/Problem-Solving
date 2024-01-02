class Solution {

public:
    int lengthOfLongestSubstring(string s) {
        int l=1,r=s.size();
        if(r==0)
          return 0;
        int ans;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(valid(s,mid))
            {

                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
        
    }
      public:
     bool valid(string s,int mid)
    {
        int cnt[256]={0};
        bool f=false;
        int distinct=0;
        int n=s.size();

        for(int i=0;i<n;i++)
        {
            cnt[s[i]]++;
            if(cnt[s[i]]==1)
                distinct++;
            if(i>=mid)
            {
                cnt[s[i-mid]]--;
                if(!cnt[s[i-mid]])
                   distinct--;
            }
            if(i>=mid-1)
            {
                if(distinct==mid)
                    f=true;
            }
        }
        return f;
    }
  
};