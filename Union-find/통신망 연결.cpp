#include<stdio.h>
#include<algorithm>
#include<vector>
#define INF 0x7fffffff
using namespace std;
typedef long long ll;
int N, M, T;
ll res;
int parent[100002], level[100002]; 
bool isit[100002];

vector<pair<int,int>> v;
vector<int> dis;

int find(int x){
	if (parent[x] == x){ 
		return x;
	}
	
	return parent[x] = find(parent[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	
	if (x == y){
		return;
	}
	
	if (level[x] > level[y]){
		swap(x,y);
	}
	
	parent[x] = y;
	level[y] += level[x];
}

int main(){
	scanf("%d%d%d",&N,&M,&T);
	for (int i = 1; i <= N; i++){
		parent[i] = i;
		level[i] = 1;
	}
	for (int i = 0; i < M; i++){
		int from,to;
		scanf("%d%d",&from,&to);
		v.push_back({from,to});
	}
	for (int i = 0; i < T; i++){
		int t;
		scanf("%d",&t);
		dis.push_back(t);
		isit[t-1] = true;
	}
	for (int i = 0; i < M; i++){
		if (!isit[i]){
			merge(v[i].first,v[i].second);
		}
	}
	for (int i = T-1; i >= 0; i--){
		int rx = find(v[dis[i]-1].first);
		int ry = find(v[dis[i]-1].second);
		if (rx != ry){
			res += (long long)level[rx] * (long long)level[ry];
		}
		merge(rx,ry);
	}
	
	printf("%lld",res);
	
	return 0;
}
