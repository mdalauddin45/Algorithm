#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
vector<int> arr(N);
int binarySearch(int l,int r,int k,int flag)
{
    int ans = -1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==k)
        {
            ans=mid;
            if(flag==1) r=mid-1;
            else l=mid+1;
        }else if(arr[mid]>k) r=mid-1;
        else l=mid+1;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cin>>k;
    int first = binarySearch(0,n-1,k,1);
    int last = binarySearch(0,n-1,k,0);

    if (first!=-1 && last!=-1 && first!=last) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}