class Solution {
public:
    int longestStrChain(vector<string>& words) {

        // sorting in sense of size;
        sort(words.begin(),words.end(),cmp);
        int n=words.size();
        vector<int>dp(n,1);
        int mxLen=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j])&& dp[i]<dp[j]+1)    dp[i]=1+dp[j];
            }
            if(dp[i]>mxLen) mxLen=dp[i];
        }

        return mxLen;
        
    }
     static bool cmp(string &s1,string &s2){
        return s1.size()<s2.size();
    }

    bool check(string &s1,string &s2){
        if(s1.size()!=1+s2.size()) return false;
        int l1=0,l2=0;
        while(l1<s1.size()){
            if(s1[l1]==s2[l2]) {
                l1++;
                l2++;
            }else {
                l1++;
            }

        }

        return l1==s1.size() && l2==s2.size();
    }

  
};