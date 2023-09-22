#include<bits/stdc++.h>
using namespace std;
void findMxValue(vector<int>h,int n){
    int first = INT_MIN;
    int second =INT_MIN;
    int index1=0;
    int index2=0;
    for(int i=0;i<n;i++){
        if(h[i]>first){
            second = first;
            first = h[i];
            index2 = index1;
            index1 = i;
        }else if(h[i]>second && h[i]!=first){
            second = h[i];
            index2=i;
        }
    }
    if (index1>index2){
            swap(index1,index2);
    }
    cout<<index1<<" "<<index2<<endl;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> h(n);
        for(int i=0;i<n;i++) cin>>h[i];
        findMxValue(h,n);
    }
    
    return 0;
}