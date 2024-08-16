class Solution {
public:
    vector<string>res;
    vector<string> generateParenthesis(int n) {
        string str="";
        int open=0;
        int close=0;
        solve(str,n,open,close);

        return res;
        
    }
    void solve(string &str,int n,int open,int close){
        if(str.size()==2*n) {
            res.push_back(str);
            return;
        }
        if(open<n){
        str.push_back('(');
        solve(str,n,open+1,close);
        str.pop_back();
        }
        if(close<open){
        str.push_back(')');
        solve(str,n,open,close+1);
        str.pop_back();
        }
    }
    bool isValid(string &s){
        int cnt=0;
        for(auto u:s){
            if(u=='(') cnt++;
            else cnt--;
            if(cnt<0) return false;
        }
        return cnt==0;
    }
};