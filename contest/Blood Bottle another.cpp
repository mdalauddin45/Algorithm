#include <bits/stdc++.h>
using namespace std;
int calculateBottlesZazaDrinks(const string s) {
    int zcnt = 0;
    int ccnt = 0;
    char curr = s[0];

    for (char c : s) {
        if (c == curr) {
            ccnt++;
        } else {
            if (curr == '1') {
                zcnt += ccnt;
            }
            ccnt = 1;
            curr = c;
        }
    }
    if (curr == '1') {
        zcnt += ccnt;
    }
    return zcnt;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        int result = calculateBottlesZazaDrinks(S);
        cout << result << endl;
    }
    return 0;
}
