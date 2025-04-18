#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll M=1e9+7;
const int N=1e6+10;
vector<int>dp(N,0);
int dicecomb(int n){
    dp[0]=1;
    dp[1]=1;
    if(n==0||n==1){
        return dp[n];
    }
    else if(dp[n]!=0){
        return dp[n];
    }
    else{
        for(int i=1;i<=6;++i){
          if(n-i>=0){
            dp[n]=(dp[n]%M+dicecomb(n-i)%M)%M;
          }
    }
    return dp[n];
    }
}
int main(){
    int n;
    cin>>n;
    cout<<dicecomb(n)<<endl;
    return 0;
}
