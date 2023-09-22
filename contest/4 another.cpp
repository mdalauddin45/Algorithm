#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            if (r == 1) {
                cout << c;
            } else if (c == 1 ) {
                cout << r;
            }else if(r==n || c==n){
                cout<< n;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
