class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto u:asteroids){
            if(u>0 or st.empty()) st.push(u);
            else {
                while(!st.empty() and st.top()>0 and st.top()<abs(u)) st.pop();
                if(!st.empty() and st.top()==abs(u)) st.pop();
                else {
                    if(st.empty() || st.top()<0) st.push(u);

                }
            }
        }
        vector<int>res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};
