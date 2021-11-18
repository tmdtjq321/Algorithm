#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 0x7fffffff
using namespace std;
struct pt{
	int e,w;
	pt(){}
	pt(int _e, int _w){
		e = _e;
		w = _w;
	}
};

bool operator<(pt a,pt b){
	return (a.w > b.w);
}
int N, M, p1,p2;
vector<pt> v[802];
int dist[802];
int dist_p1[802];
int dist_p2[802];

void dijkstra(int s, int dist[]){
	for (int i = 1; i <= N; i++){
		dist[i] = INF;
	}
	dist[s] = 0;
	priority_queue<pt> pq;
	pq.push({s,0});
	while(!pq.empty()){
		int cur = pq.top().e;
		int val = pq.top().w;
		pq.pop();
		if (dist[cur] < val){
			continue;
		}
		for (int i = 0; i < v[cur].size(); i++){
			int des = v[cur][i].e;
			int cost = v[cur][i].w + dist[cur];
			if (dist[des] > cost){
				dist[des] = cost;
				pq.push({des,cost});
			}
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for (int i = 0; i < M; i++){
		int from, to, w;
		scanf("%d%d%d",&from,&to,&w);
		v[from].push_back({to,w});
		v[to].push_back({from,w});
	}	
	scanf("%d%d",&p1,&p2);
	dijkstra(1,dist);
	dijkstra(p1,dist_p1);
	dijkstra(p2,dist_p2);
	int len1, len2; 
	if (dist[p1] != INF  && dist_p1[p2] != INF && dist_p2[N] != INF){
		len1 = dist[p1] + dist_p1[p2] + dist_p2[N];
	}
	else{
		len1 = INF;
	}
	if (dist[p2] != INF  && dist_p2[p1] != INF && dist_p1[N] != INF){
		len2 = dist[p2] + dist_p2[p1] + dist_p1[N];
	}
	else{
		len2 = INF;
	}
	if (len1 == INF && len2 == INF){
		printf("-1");
	}
	else{
		if (len1 > len2){
			printf("%d",len2);
		}
		else{
			printf("%d",len1);
		}
	}
	return 0;
}
