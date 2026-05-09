#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>nums;
int dp[1000][1000];

int LIS(int i, int p){
    if(i >= n)return 0;
    if(dp[i][p+1] != -1)return dp[i][p+1];
    int skip = LIS(i+1, p);
    int take = 0;
    if(p == -1 || nums[i] > nums[p]){
        take = 1+LIS(i+1,i);
    }
    return dp[i][p+1]=max(take,skip);
}
int main(){
    cin>>n;
    nums.resize(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<LIS(0,-1)<<endl;
    return 0;

}
