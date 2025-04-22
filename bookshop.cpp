#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll M=1e9+7;
int bookshop(vector<int>&cost,vector<int>&pages,int n,int x){
  vector<int>prev(x+1,0);
  vector<int>curr(x+1,0);
  for(int i=1;i<=n;++i){
    for(int j=0;j<=x;++j){
        int cos=cost[i-1];
        int pag=pages[i-1];
        int pick=(j>=cos?pag+prev[j-cos]:0);
        int skip=prev[j];
        curr[j]=max(pick,skip);
    }
    for(int u=0;u<=x;++u){
        prev[u]=curr[u];
    }
  }
  return prev[x];
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>cost(n);
    for(int i=0;i<n;++i){
        cin>>cost[i];
    }
    vector<int>pages(n);
    for(int i=0;i<n;++i){
        cin>>pages[i];
    }
    cout<<bookshop(cost,pages,n,x)<<endl;
    return 0;
}