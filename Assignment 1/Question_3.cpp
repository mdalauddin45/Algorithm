#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
vector<int> arr(N);
int lower(int l,int r,int k)
{
    int ans = -1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==k)
        {
            ans=mid;
            r=mid-1;
        }else if(arr[mid]>k) r=mid-1;
        else l=mid+1;
    }
    return ans;  
}
int upper(int l,int r,int k)
{
    int ans = -1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==k)
        {
            ans=mid;
            l=mid+1;
        }else if(arr[mid]>k) r=mid-1;
        else l=mid+1;
    }
    return ans; 
}
bool multipleValue(int l,int r,int k)
{
    int first = lower(l,r,k);
    int last = upper(l,r,k);
    return first!=-1 && last!=-1 && first!=last;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cin>>k;
    if (multipleValue(0,n-1,k)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}