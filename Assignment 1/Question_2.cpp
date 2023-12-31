#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int arr[N];
int binarySearch(int l,int r,int k)
{
    while (l<=r)
    {
        int mid=(l+r)/2;

        if(arr[mid]==k) return mid;
        else if(arr[mid]>k) r=mid-1;
        else l=mid+1;
    }
    return -1;  
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cin>>k;
    int ans = binarySearch(0,n-1,k);
    if(ans==-1) cout<<"Not Found";
    else cout<<ans;
    return 0;
}