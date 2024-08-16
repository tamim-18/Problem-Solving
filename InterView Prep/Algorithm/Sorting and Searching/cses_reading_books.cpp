#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        if (all_of(a.begin(), a.end(), [](int x) { return x == 0; })) {
            cout << 0 << endl;
            continue;
        }
        
        int steps = 0;
        vector<int> operations;
        
        while (steps < 40 && !all_of(a.begin(), a.end(), [](int x) { return x == 0; })) {
            sort(a.begin(), a.end());
            int x = a[n / 2]; // Choose median
            operations.push_back(x);
            for (int i = 0; i < n; ++i) {
                a[i] = abs(a[i] - x);
            }
            ++steps;
        }
        
        if (steps == 40 && !all_of(a.begin(), a.end(), [](int x) { return x == 0; })) {
            cout << -1 << endl;
        } else {
            cout << steps << endl;
            for (int i = 0; i < steps; ++i) {
                cout << operations[i] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
