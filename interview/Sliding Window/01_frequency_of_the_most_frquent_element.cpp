class Solution {
public:
    int maxFrequency(vector<int>& a, int k) {
        long long sum=0;
        int i=0;
        int n=a.size();
        sort(a.begin(),a.end());
        int  mx=0;
        for(int j=0;j<n;j++){
            sum+=a[j];
            while((long)(j-i+1)*a[j]-sum>k) sum-=a[i++];
            mx=max(mx,j-i+1);
        }

        return mx;
        
    }
};