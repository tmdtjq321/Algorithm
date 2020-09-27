#include<stdio.h>
#include<math.h>
#include<queue>
#include<memory.h>
using namespace std;
#define MAX 1003
struct Point{int x,y;};
int N,K;
int chk[MAX], d[MAX][MAX];
Point arr[MAX];
inline int dist(Point A, Point B){
  return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}
int f(int tmp){
  queue<int> Q;
  memset(chk, -1, sizeof(chk));
  Q.push(0), chk[0] = 0;
  while(!Q.empty()){
    int cur = Q.front();
    printf("\nqueue in %d\n",cur);
    Q.pop();
    if(chk[cur]>K+1) return 0;
    else if(cur==N+1) return 1;
    for(int i=0;i<=N+1;i++)
      if(chk[i]==-1 && d[cur][i]<tmp*10){
        chk[i]=chk[cur]+1;
        printf("%d ",chk[i]);
        Q.push(i);
      }
  }  
  return 0;
}

int main(){
  scanf("%d%d",&N,&K);
  arr[0].x = arr[0].y = 0;
  arr[N+1].x = arr[N+1].y = 10000;
  for(int i=1;i<=N;i++) scanf("%d%d",&arr[i].x,&arr[i].y);
  for(int i=0;i<N+1;i++) for(int j=0;j<=N+1;j++) d[i][j] = (int)sqrt(dist(arr[i],arr[j]));
  int s = 0;
  int e = 14142;
  int mid;
  while(s<e){
    mid=(s+e-1)/2;
    printf("%d\n",mid);
    if(f(mid)) e = mid;
    else s = mid+1;
  }
  printf("%d\n",e);
  return 0;
}
