class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++) v.push_back({start[i],end[i]});
        sort(v.begin(),v.end(),cmp);
        int cnt=1;
        int lastEnd=v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first>lastEnd) {
                cnt++;
                lastEnd=v[i].second;
            }
        }
        return cnt;
    }
    static bool cmp(const pair<int,int>&a, const pair<int,int>&b) 
        {return a.second<b.second;}
};