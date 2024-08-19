class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);  // Start with the first ugly number
        
        long long ugly = 0; // Variable to store the nth ugly number
        for (int i = 0; i < n; ++i) {
            ugly = *s.begin();
            s.erase(s.begin());
            
            // Generate the next set of ugly numbers
            s.insert(ugly * 2);
            s.insert(ugly * 3);
            s.insert(ugly * 5);
        }
        
        return (int)ugly;
    }
};
