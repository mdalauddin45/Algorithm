#include<bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t) {
    int n = s.size();
    int m = t.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == n;
}
int main()
{
    string s,t;
    cin>>s>>t;
    if(isSubsequence(s,t)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}