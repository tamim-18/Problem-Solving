class Solution
{
    public:
        string countOfAtoms(string formula)
        {
            int n = formula.size();
            stack<unordered_map<string, int>> st;
            st.push(unordered_map<string, int> ());
            int i = 0;
            while (i < n)
            {
                if (formula[i] == '(') {
                    st.push(unordered_map<string, int> ());
                    i++;
                } 
                else if (formula[i] == ')')
                {
                    auto curr = st.top();
                    st.pop();
                    string mul;
                    i++; // Move past ')'
                    while (i < n && isdigit(formula[i])) {
                        mul.push_back(formula[i]);
                        i++;
                    }
                    int mult = mul.empty() ? 1 : stoi(mul); // Default multiplier is 1
                    for (auto& u: curr)
                    {
                        string el = u.first;
                        int cnt = u.second;
                        curr[el] = cnt * mult;
                    }

                    // Merging 
                    for (auto& u: curr)
                    {
                        string element = u.first;
                        int cnt = u.second;
                        st.top()[element] += cnt; // Accessing the top of the stack which is a map
                    }
                }
                else {
                    string currElement; //Mg, H, Ne.
                    currElement.push_back(formula[i]);
                    i++;
                    while(i < n && isalpha(formula[i]) && islower(formula[i])){
                        currElement.push_back(formula[i]);
                        i++;
                    }
                    string cnt;
                    while(i < n && isdigit(formula[i])){
                        cnt.push_back(formula[i]); //Mg23 // CurrentElement=Mg and cnt=23
                        i++;
                    }
                    int cn = cnt.empty() ? 1 : stoi(cnt); // Default count is 1
                    st.top()[currElement] += cn;
                }
            }
            string res;
            // Sorted map because there will be only one map in the stack
            map<string, int> sortedMap(begin(st.top()), end(st.top()));
            for(auto& u: sortedMap){
                string el = u.first;
                res += el;
                int cnt = u.second;
                if(cnt > 1)
                {
                    res += to_string(cnt);
                }
            }
            return res;
        }
};
