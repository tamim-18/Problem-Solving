class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>>v;
        for(auto u:intervals) {
            v.push_back({u[0],u[1]});
        }
        sort(v.begin(),v.end(),cmp);
        int cnt=1;
        int last=v[0].second;
        for(int i=1;i<v.size();i++){
            if(v[i].first>=last){
                cnt++;
                last=v[i].second;
            }
        }
        return v.size()-cnt;

        
    }
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
};
