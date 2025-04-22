#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll M=1e9+7;
const int X=1e6;
const int INF=1e9;
vector<int>dp(X+1,INF);
int mincoins(vector<int>&vec,int x){
    dp[0]=0;
    for(int j=1;j<=x;++j){
        for(int i=0;i<vec.size();++i){
            if(j>=vec[i]){
                dp[j]=min(dp[j],dp[j-vec[i]]+1);
            }
            else{
                break;
            }
        }
    }
    if(dp[x]==INF){
        return -1;
    }
    return dp[x];
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>vec(n);
    for(int i=0;i<n;++i){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    cout<<mincoins(vec,x)<<endl;
    return 0;
}