class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>st;
        for(auto &email:emails)
        {
            string localName;
            for(auto u:email)
            {
                if(u=='+' or u=='@') break;
                if(u=='.') continue;
                localName+=u;
            }
            string domainName=email.substr(email.find('@'));
            localName+=domainName;
            st.insert(localName);

            

        }
        return st.size();
       
    }
};
// intution behind the problem:
// 1. we have to find the unique email addresses
// 2. we have to ignore the '.' and '+' in the local name
// 3. we have to ignore the characters after the '+' sign
