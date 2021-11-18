#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;

struct pt{
	int e, w, t;
	pt(){}
	pt(int _e, int _w, int _t){
		e = _e;
		w = _w; 
		t = _t;
	}
};

bool operator<(pt a, pt b){
	return (a.t > b.t);
}

vector<pt> v[102];
int N, M, T, K;
int dist[102][10002];

void dijkstra(){
	for (int i = 0; i <= N; i++){
		for (int j = 0; j <= M; j++){
			dist[i][j] = INF;
		}
	}
	dist[1][0] = 0;
	priority_queue<pt> pq;
	pq.push({1,0,0});
	while(!pq.empty()){
		int cur = pq.top().e;
		int val = pq.top().w;
		int time = pq.top().t;
		pq.pop();
		if (dist[cur][val] < time){
			continue;
		}
		for (int i = 0; i < v[cur].size(); i++){
			int des = v[cur][i].e;
			int pay = v[cur][i].w + val;
			int cost = v[cur][i].t + time;
			if (pay > M){
				continue;
			}
			if (dist[des][pay] > cost){
				for (int i = pay; i <= M; i++){
					if (dist[des][i] > cost){
						dist[des][i] = cost;
						pq.push({des,pay,cost});
					}
				}
			}
		}
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&N,&M,&K);
		for (int i = 0; i < K; i++){
			int from,to,w,t;
			scanf("%d%d%d%d",&from,&to,&w,&t);
			v[from].push_back({to,w,t});
		} 
		dijkstra();
		
		int res = INF;
		for (int i = 1; i <= M; i++){
			printf("%d\n",dist[N][i]);
			if (dist[N][i] < res){
				res = dist[N][i];
			}
		}
		if (res != INF){
			printf("%d\n",res);
		}
		else{
			printf("Poor KCM\n");
		}
		for (int i = 1; i <= N; i++){
			while(!v[i].empty()){
				v[i].pop_back();
			}
		}
	} 
	return 0;
}
