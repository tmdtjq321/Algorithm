#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
typedef long long ll;
int S, N, M, E, t;
struct pt{
	int e, w;
	pt(){}
	pt(int _e, int _w){
		e = _e;
		w = _w;
	}
};

bool operator<(pt _a, pt _b){
	return(_a.w > _b.w);
}

vector<pt> v[2020];
vector<int> p;
int dist_S[2020];
int dist_G[2020];
int dist_H[2020];
int val;
bool ispos[2020];

void dijkstra(int x, int dist[]){
	priority_queue<pt> pq;
	pq.push((pt){x,0});
	while(!pq.empty()){
		int cost = pq.top().w;	// 가중치 
		int pos = pq.top().e;	// 도착점 
		pq.pop();
		if (dist[pos] < cost){ // 현재 지점에서 가는게 비용이 더 들면 패스 
			continue;
		}
		for (int i = 0; i < v[pos].size(); i++){
			int des = v[pos][i].e;
			int next = cost + v[pos][i].w;
			if (dist[des] > next){
				dist[des] = next;
				pq.push((pt){des,next});
			}
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&N,&M,&t);
		int s,g,h;
		scanf("%d%d%d",&s,&g,&h);
		for (int i = 0; i < M; i++){
			int from, to, weight;
			scanf("%d%d%d",&from,&to,&weight);
			v[from].push_back((pt){to,weight});
			v[to].push_back((pt){from,weight});
			if ((g == from && h == to) || (g == to && h == from)){
				val = weight;
			}
		}
		
		for (int i = 0; i < t; i++){	// 목적지후보 
			int tmp;
			scanf("%d",&tmp);
			p.push_back(tmp);
		}
		sort(p.begin(),p.end());
		
		for (int i = 1; i <= N; i++){
			dist_S[i] = INF;
			dist_G[i] = INF;
			dist_H[i] = INF;
		}
		
		dist_S[s] = 0;
		dist_G[g] = 0;
		dist_H[h] = 0;
		dijkstra(s,dist_S);
		dijkstra(g,dist_G);
		dijkstra(h,dist_H);
		
		for (int i = 0; i < p.size(); i++){
			if (dist_S[g] + val + dist_H[p[i]] == dist_S[p[i]]){
				printf("%d ",p[i]);
				continue;
			}
			if (dist_S[h] + val + dist_G[p[i]] == dist_S[p[i]]){
				printf("%d ",p[i]);
				continue;
			}
		}
		printf("\n");
		for (int i = 1; i <= N; i++){
			while(!v[i].empty()){
				v[i].pop_back();
			}
		}
		while(!p.empty()){
			p.pop_back();
		}
		
	}
	
	return 0;
}
