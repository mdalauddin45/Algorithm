#include<bits/stdc++.h>
using namespace std;
bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for (int num : nums) {
        s += num;
        }
        if(s%2) return false;
        int mid=s/2;
        vector<vector<bool>> dp(n + 1, vector<bool>(mid + 1, false));
        for(int i=0;i<=n;i++) dp[i][0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=mid;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    return dp[n][mid];
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    if(canPartition(arr)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}