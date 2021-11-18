#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct edge{
	int f, t, w;
};

bool operator<(edge a, edge b){
	return (a.w > b.w);
} 

int N,M, res;
int par[10002];
priority_queue<edge> pq;

int find(int x){
	if (par[x] == x){
		return x;
	}
	
	return par[x] = find(par[x]);
}

bool merge(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b){
		return false;
	}
	par[a] = b;
	return true;
}


int main(){
	scanf("%d%d",&N,&M);
	for (int i = 0; i < N; i++){
		par[i] = i;
	}
	
	for (int i = 0; i < M; i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		pq.push({a,b,c});
	}
	while(!pq.empty()){
		int from = find(pq.top().f);
		int to = find(pq.top().t);
		int cost = pq.top().w;
		pq.pop();
		if (merge(from,to)){
			res += cost;
		}
	}
	printf("%d",res);
	
	return 0;
}
