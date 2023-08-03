#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> arr(N);

bool hasMultipleOccurrences(int l, int r, int k) {
    int first = lower_bound(arr.begin() + l, arr.begin() + r + 1, k) - arr.begin();
    int last = upper_bound(arr.begin() + l, arr.begin() + r + 1, k) - arr.begin();
    return (last - first) > 1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    
    if (hasMultipleOccurrences(0, n - 1, k))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}
