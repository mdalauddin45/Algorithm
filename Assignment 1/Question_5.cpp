#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int arr1[N];
int arr2[N];
int result[N+N];
void mergeArrays(int n,int m)
{
    for(int i=0,j=0,k=0;k<m+n;k++)
    {
        if(i<n && (j>=m || arr1[i]>=arr2[j])){
            result[k]=arr1[i];
            i++;
        }
        else{
            result[k]=arr2[j];
            j++;
        }
    }   
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr1[i];
    int m;
    cin>>m;
    for(int i=0;i<m;i++) cin>>arr2[i];

    //merge
    mergeArrays(n,m);
    for(int i=0;i<n+m;i++) cout<<result[i]<<" ";
    return 0;
}