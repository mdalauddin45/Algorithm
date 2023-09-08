#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int marks[n], total_marks = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> marks[i];
            total_marks += marks[i];
        }

        if (total_marks == 1000) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
