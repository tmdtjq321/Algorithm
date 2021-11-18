// Suffix array¿Í LCP
#include<cstdio>
#include<algorithm>
#include<cstring>
const int MAXN = 600000;
using namespace std;
char str[MAXN];
int SA[MAXN],LCP[MAXN];
int r[MAXN];
int g[MAXN],tg[MAXN];
int t,n;
bool cmp(int x, int y){
  if(g[x] == g[y]){
    return g[x+t]<g[y+t];
  }
  return g[x]<g[y];
}
void getSA(const char* str){
  t = 1;
  n = (int)strlen(str);
  for(int i=0;i<n;i++){
    SA[i]=i;
    g[i] = str[i] - 'a';
  }
  while(t<=n){
    g[n] = -1;
    sort(SA,SA+n,cmp);
    for(int i=0;i<n;i++){
  		printf("%d ",SA[i] + 1);
  	}
 	 printf("\n");
    tg[SA[0]] = 0;
    for(int i=1;i<n;i++){
      if(cmp(SA[i-1],SA[i]))
        tg[SA[i]] = tg[SA[i-1]] + 1;
      else
        tg[SA[i]] = tg[SA[i-1]];
    }
    for(int i=0;i<n;i++)
      g[i] = tg[i];
    t<<=1;
  }
}
int main(){
  scanf("%s",str);
  getSA(str);
  for(int i=0;i<n;i++)
    r[SA[i]] = i;
  int len = 0;
  //LCP
  for(int i=0;i<n;i++){
    int k = r[i];
    if(k){
      int j = SA[k-1];
      while(str[j+len] == str[i+len]) len++;
      LCP[k] = len;
      if(len) len--;
    }
  }
  for(int i=0;i<n;i++){
  	printf("%d ",SA[i] + 1);
  }
  printf("\n");
  for(int i=0;i<n;i++){
    if(i == 0) printf("x ");
    else printf("%d ",LCP[i]);
  }
  return 0;
} 

banana	1
anana	2
nana	3
ana		4
na		5
a		6








