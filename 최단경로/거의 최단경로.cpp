#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct pt{
	int e, w;
	pt(){}
	pt(int _e, int _w){
		e = _e;
		w = _w;
	}
};

bool operator<(pt _a,pt _b){
	return (_a.w > _b.w);
}

int N,M,S,E;
int dist[502];
int adj[502][502];

void dijkstra(){
	for (int i = 0; i < N; i++){
		dist[i] = INF;
	}
	dist[S] = 0;
	priority_queue<pt> pq;
	pq.push({S,0});
	while(!pq.empty()){
		int ar = pq.top().e;
		int val = pq.top().w;
		pq.pop();
		if (dist[ar] < val){
			continue;
		}
		for (int i = 0; i < N; i++){
			if (adj[ar][i]){
				int des = i;
				int cost = adj[ar][i] + val;
				if (dist[des] > cost){
					dist[des] = cost;
					pq.push({des,cost});
				}
			}
		}
	}
}

void cut(int d){
	for (int i = 0; i < N; i++){
		if (adj[i][d] != 0 && dist[d] == dist[i] + adj[i][d]){
			adj[i][d] = 0;
			cut(i);
		}
	}
}

int main(){
	while(1){
		scanf("%d%d",&N,&M);
		if (N == 0 && M == 0){
			break;
		}
		scanf("%d%d",&S,&E);
		memset(adj,0,sizeof(adj));
		for (int i = 0; i < M; i++){
			int from, to, weight;
			scanf("%d%d%d",&from,&to,&weight);
			adj[from][to] = weight;
		}
		dijkstra();
		cut(E);
		dijkstra();
		if (dist[E] == INF){
			printf("-1\n");
		}
		else{
			printf("%d\n",dist[E]);
		}
	}
	
	return 0;
}
