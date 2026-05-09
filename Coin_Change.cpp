#include<bits/stdc++.h>
using namespace std;

int dp[1000][1001];
vector<int>coins;
int coinChange(int i,int target){
    if(target == 0)return 1;
    if(i >= coins.size()||target<0)return 0;
    if(dp[i][target] != -1){
        return dp[i][target];
    }
    int skip = coinChange(i+1,target);
    int take = 0;
    if(coins[i]<=target){
        take = coinChange(i, target-coins[i]);
    }
    return dp[i][target]=take+skip;
}
int main(){
    int n, target;
    cin>>n>>target;
    coins.resize(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<coinChange(0,target);
    return 0;
}
