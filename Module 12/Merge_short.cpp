#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int mid,int r)
{
    int ls=mid-l+1;
    int rs=r-mid;
    int L[ls];
    int R[rs];
    int k=0;
    for(int i=0;i<ls;i++){
        L[k]=arr[i];
        k++;
    }
    k=0;
    for(int i=0;i<rs;i++){
        R[k]=arr[mid+1+i];
        k++;
    }
    int i=0,j=0;
    int curr=l;
   while (i<rs && j<ls)
   {
    if(L[i]<R[j])
    {
        arr[curr]=L[i];
        i++;
    }else{
        arr[curr]=R[j];
        j++;
    }
    curr++;
   }
   
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    merge(arr,0,3,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}