// ���ī��  
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
        while (j > 0 && a[i] != b[j])        //���� j��ŭ ã�Ҵµ� �̹��� ���ϴ� ���ڰ� �ٸ� ���
            j = pi[j - 1];        //���ڿ� B�� failure function ���� ���� �񱳸� ���ݴϴ�.
        if (a[i] == b[j]){            //���ϴ� ���ڰ� ���� ���
            if (j == b.length() - 1){    //���ڿ� B�� ���� Ž���Ͽ��� ������ �信 ��ġ�� �־��ݴϴ�.
                res.push_back(i - b.length() + 2);
                j = pi[j];    //���� Ž���� ���Ͽ� �̹����� failure function ���� ���� �񱳸� ���ݴϴ�.
            }
            else
                j++;    //���ڿ� B�� ���� �ܾ �����ݴϴ�.
        }
    }
}
void getpi(){
    pi.resize(b.length());
    int j = 0;
    for (int i = 1; i < b.length(); i++){
        while (j > 0 && b[i] != b[j])
            j = pi[j - 1];        //����ġ�� �Ͼ ���
        if (b[i] == b[j])
            pi[i] = ++j;        //prefix�� ���� ����ġ��ŭ pi�� �����ݴϴ�.
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
// Suffix array�� LCP
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

