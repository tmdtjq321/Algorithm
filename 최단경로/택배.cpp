#include<stdio.h>
#include<vector>
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

bool operator<(pt _a, pt _b){
	return (_a.w > _b.w);
}

int N, M;
int res[202][202];
int dist[202];
vector<pt> v[202];

void dijkstra(int s){
	for (int i = 1; i <= N; i++){
		dist[i] = INF;
	}
	dist[s] = 0;
	priority_queue<pt> pq;
	pq.push({s,0});
	while(!pq.empty()){
		int ar = pq.top().e;
		int val = pq.top().w;
		pq.pop();
		if (dist[ar] < val){
			continue;
		}
		for (int i = 0; i < v[ar].size(); i++){
			int des = v[ar][i].e;
			int cost = v[ar][i].w + val;
			if (dist[des] > cost){
				dist[des] = cost;
				res[des][s] = ar;
				pq.push({des,cost});
			}
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	memset(res,0,sizeof(res));
	while(M--){
		int from, to, w;
		scanf("%d%d%d",&from,&to,&w);
		v[from].push_back({to,w});
		v[to].push_back({from,w});
	}
	for (int i = 1; i <= N; i++){
		dijkstra(i);
	}
	
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (res[i][j]){
				printf("%d ",res[i][j]);
			}
			else{
				printf("- ");
			}
			
		}
		printf("\n");
	}
	
	
	return 0;
}
