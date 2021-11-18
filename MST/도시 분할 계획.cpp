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

int N,M, res,max_num;
int par[100002];
priority_queue<edge> pq;

int find(int x){
	if (par[x] == x){
		return x;
	}
	
	return par[x] = find(par[x]);
}

int main(){
	scanf("%d%d",&N,&M);
	for (int i = 1; i <= N; i++){
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
		if (from == to){
			continue;
		}
		if (max_num < cost){
			max_num = cost;
		}
		par[from] = to;
		res += cost;
	}
	
	printf("%d",res-max_num);
	
	return 0;
}
