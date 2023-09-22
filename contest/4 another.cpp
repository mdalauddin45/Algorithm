#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Handle the case when n is 1 separately
    if (n == 1) {
        cout << "1" << endl;
        return 0;
    }

    // Print the first line with numbers from 1 to n
    for (int i = 1; i <= n; ++i) {
        cout << i;
    }
    cout << endl;

    // Print the lines with modified format
    for (int i = 2; i < n; i++) {
        cout << i;
        for (int j = 2; j <n-1; j++) {
            cout << " ";
        }
        cout << " " << n << endl;
    }

    // Print the last line with all n's
    for (int i = 1; i <= n; ++i) {
        cout << n;
    }
    cout << endl;

    return 0;
}
