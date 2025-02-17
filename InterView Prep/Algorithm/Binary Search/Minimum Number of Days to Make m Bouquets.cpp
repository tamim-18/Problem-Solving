class Solution {
public:
    bool valid(vector<int>& bloomDay, int m,int k,int mid)
    {
        int cnt=0,boquet=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=mid)
                cnt++;
            else 
            {
                // cout<<cnt<<endl;
                boquet+=(cnt/k);
                cnt=0;
            }
        }
        boquet+=(cnt/k);
        // cout<<boquet<<endl;
        if(boquet>=m)
            return true;
        return false;

    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long  mul=(long long)k*m;
        if(mul>n) return -1;
        int mx=INT_MIN,mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]>mx)
                mx=bloomDay[i];
            if(bloomDay[i]<mn) mn=bloomDay[i];
        }
       int l=mn,r=mx;
       cout<<l<<" "<<r<<endl;
       int res;
       while(l<=r)
       {
           int mid=l+(r-l)/2;
           if(valid(bloomDay,m,k,mid))
                {
                    res=mid;
                    r=mid-1;
                }
            else l=mid+1;
       }
       return res;
        
    }
}