#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;

        int ZazaCount = 0;
        int KazaCount = 0;
        int i = 0;
        int n = S.size();

        while (i < n) {
            char currentType = S[i];
            int consecutiveCount = 0;

            while (i < n && S[i] == currentType) {
                consecutiveCount++;
                i++;
            }

            if (currentType == '1') {
                ZazaCount += consecutiveCount;
            } else {
                KazaCount += consecutiveCount;
            }
        }

        cout << ZazaCount << endl;
    }

    return 0;
}
