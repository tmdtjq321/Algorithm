// 라빈카프  
#include<stdio.h>
#include<string.h>
const int MOD = 100003;
typedef long long ll;
int mod(ll n){
  if(n>=0) return n%MOD;
  return ((-n/MOD+1)*MOD+n)%MOD;
}
char pattern[100000000];
char target[100000000];
int H,G;
int power=1;
int main(){
  scanf("%s",pattern);
  scanf("%s",target);
  int pl = strlen(pattern);
  int tl = strlen(target);
  for(int i=0;i<pl;i++){
    H+=mod(1LL*pattern[pl-i-1] * power);
    G+=mod(1LL*target[pl-i-1] * power);
    if(i!=pl-1) power = mod(power*2);
  }
  printf("H===%d\n",H);
  for(int i=pl;i<tl;i++){
    G = mod(2*(G-1LL*target[i-pl]*power)+target[i]);
    printf("%d\n",G);
  }
  return 0;
}
// KMP    
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
string a,b;
vector<int> pi;
vector<int> res;
void kmp(){
    int j = 0;
    for (int i = 0; i < a.length(); i++){
        while (j > 0 && a[i] != b[j])        //현재 j만큼 찾았는데 이번에 비교하는 문자가 다른 경우
            j = pi[j - 1];        //문자열 B를 failure function 이후 부터 비교를 해줍니다.
        if (a[i] == b[j]){            //비교하는 문자가 같은 경우
            if (j == b.length() - 1){    //문자열 B를 전부 탐색하였기 때문에 답에 위치를 넣어줍니다.
                res.push_back(i - b.length() + 2);
                j = pi[j];    //다음 탐색을 위하여 이번에도 failure function 이후 부터 비교를 해줍니다.
            }
            else
                j++;    //문자열 B의 다음 단어를 비교해줍니다.
        }
    }
}
void getpi(){
    pi.resize(b.length());
    int j = 0;
    for (int i = 1; i < b.length(); i++){
        while (j > 0 && b[i] != b[j])
            j = pi[j - 1];        //불일치가 일어날 경우
        if (b[i] == b[j])
            pi[i] = ++j;        //prefix가 같은 가중치만큼 pi를 정해줍니다.
    }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  getline(cin,a);
  getline(cin,b);
  getpi();
  kmp();
  cout << res.size() << "\n";
  for(int i=0;i<res.size();i++)
    cout << res[i] << "\n";
  return 0;
}
// Suffix array와 LCP
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
  for(int i=0;i<n;i++)
    printf("%d ",SA[i] + 1);
  printf("\n");
  for(int i=0;i<n;i++){
    if(i == 0) printf("x ");
    else printf("%d ",LCP[i]);
  }
  return 0;
} 

