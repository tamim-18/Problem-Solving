#include <iostream>
#include <vector>
using namespace std;

vector<long long> getSequence(long long n) {
    vector<long long> sequence;
    long long current = 1;

    while (current <= n) {
        sequence.push_back(current);
        current = current << 1;
    }

    if (sequence.back() != n) {
        sequence.push_back(n);
    }

    return sequence;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        vector<long long> sequence = getSequence(n);
        cout << sequence.size() << endl;
        for (long long num : sequence) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
