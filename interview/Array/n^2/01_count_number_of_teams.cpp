class Solution {
    
    
public:
    int numTeams(vector<int>& rating) {
        
        int cnt=0;
        int n=rating.size();
        for(int i=0;i<n;i++){
            int left_less=0,left_greater=0,right_greater=0,right_less=0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i]) left_less++;
                else if(rating[j]>rating[i]) left_greater++;
            }
            for(int k=i+1;k<n;k++){
                if(rating[k]>rating[i]) right_greater++;
                else if(rating[i]>rating[k]) right_less++;
            }
            cnt+=left_less*right_greater+right_less*left_greater;
        }


        return cnt;
        
        
    }
};