class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        int cnt=0;
        int mx=0;
        int i=0;
        int j=0;
        while(i<n){
            if(arr[i]<=dep[j]){
                 cnt++;
                 i++;
            }
            else {
                cnt--;
                j++;
            }
            mx=max(mx,cnt);
        }
        return mx;
    	
    	
    }
    
};
