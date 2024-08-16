class Solution{
	public:
	    vector<string>res;
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string ss="";
		    solve(s,0,ss);
		    sort(res.begin(),res.end());
		    return res;
		}
		void solve(string &s,int id, string &ss){
		    if(id==s.size()){
		        if(!ss.empty()) res.push_back(ss);
		       return;
		    }
		    //take
		    ss.push_back(s[id]);
		    solve(s,id+1,ss);
		    ss.pop_back();
		    solve(s,id+1,ss);
		}
};

