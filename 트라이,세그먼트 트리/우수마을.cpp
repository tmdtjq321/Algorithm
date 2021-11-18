#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
inline int max(int a, int b){return a>b?a:b;}
const int N = 10001;
vector<int> tree[N];
int n, arr[N], dp[N][2];
bool vis[N];
int dfs(int idx, int k){
  if(dp[idx][k]!=-1) {
  	return dp[idx][k];
  }
  vis[idx] = 1;
  dp[idx][k] = 0;
  for(int t = 0; t < tree[idx].size(); t++){
    if(!vis[tree[idx][t]]){
      int tmp = dfs(tree[idx][t],0);
      if(k==0) {
      	tmp = max(tmp,dfs(tree[idx][t],1));
	  }
      dp[idx][k]+=tmp;
    }
  }
  vis[idx] = 0;
  if (k == 1){
  	dp[idx][k]+=arr[idx];
  }
  return dp[idx][k];
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",arr+i);
  for(int i=0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  memset(dp,-1,sizeof(dp));
  printf("%d",max(dfs(1,1),dfs(1,0)));
  return 0;
}
