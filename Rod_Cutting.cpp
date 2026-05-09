#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>price;
int dp[1000][1001];
int rodCutting(int i, int len){
    if(i>n||len==0)return 0;
    if(dp[i][len] != -1)return dp[i][len];
    int skip=rodCutting(i+1,len);
    int take=0;
    if(i<=len){
        take=price[i]+rodCutting(i,len-i);
    }
    return dp[i][len]=max(take,skip);
}
int main(){
    int len;
    cin>>n>>len;
    price.resize(n+1);
    price[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>price[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rodCutting(1, len);
    return 0;

}
