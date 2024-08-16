#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
 
    int t;
    cin >> t;
 
    while (t--) {
        long long n, x;
        cin >> n >> x;
 
        long long cnt = 0;
 
        for (long long a = 1; a <= x; ++a) {
            for (long long b = 1; b <= x; ++b) {
                if (a + b + 1 > x) break;
                long long ab = a * b;
                if (ab > n) break;
                long long c_max = min(x - a - b, (n - ab) / (a + b));
                if (c_max >= 1) {
                    cnt += c_max;
                }
            }
        }
 
        cout << cnt << endl;
    }
 
    return 0;
}