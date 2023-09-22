#include<bits/stdc++.h>
using namespace std;
int main()
{
    string word1,word2;
    while (cin>>word1>>word2)
    {
        int i=0,j=0;
        int n=word1.length();
        int m=word2.length();
        while (i<n)
        {
            if(word1[i]==word2[j]){
                j++;
            }
            i++;
        }
        if(j==m) cout<<"Possible"<<endl;
        else cout<<"Impossible"<<endl;
    }
    return 0;
}