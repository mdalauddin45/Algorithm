#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1" << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        cout << i;
    }
    cout << endl;
    for(int i = 2; i < n; i++) {
        cout << i;
        for(int j = 1; j < i; j++) { 
            cout << " ";
        }
        cout << n << endl;
    }
    for (int i = 1; i <= n; ++i) {
        cout << n;
    }
    cout <<endl;
    return 0;
}
// i wanna this code midify for 
// input is
// 1
// output 
// 1
// intput
// 2
// output
// 12
// 22
// input
// 3
// output
// 123
// 2 3
// 333
// input
// 4
// output 
// 1234
// 2  4
// 3  4
// 4444
// input
// 5
// output 
// 12345
// 2   5
// 3   5
// 4   5
// 55555