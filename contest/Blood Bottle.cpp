#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int n=s.length();
        int i=0,j=0;
        int result=0;
        while (i<n)
        {
            if(s[i]=='1'){
                while (i<n && s[i]=='1')
                {
                    j++;
                    i++;
                }
                result +=j;
                j=0;
            }else {
                i++;
            }
        }
        cout<<result<<endl;
        
    }
    
    return 0;
}