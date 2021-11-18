#include<stdio.h>
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

int dist[1002];
vector<pt> v[1002];
vector<int> track[1002];
int N, M;

void dijkstra(){
	for (int i = 2; i <= N; i++){
		dist[i] = INF;
	}
	priority_queue<pt> pq;
	pq.push((pt){1,0});
	while(!pq.empty()){
		pt cur = pq.top();
		int ar = cur.e;
		int weight = cur.w;
		pq.pop();
		if (dist[ar] < weight){
			continue;
		}
		for (int i = 0; i < v[ar].size(); i++){
			int des = v[ar][i].e;
			int cost = v[ar][i].w + weight;
			if (dist[des] > cost){
				dist[des] = cost;
				pq.push({des,cost});
				
				track[des].clear();
				track[des].push_back(ar);				
			}
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for (int i = 0; i < M; i++){
		int from, to, weight;
		scanf("%d%d%d",&from,&to,&weight);
		v[from].push_back({to,weight});
		v[to].push_back({from,weight});
	}
	dijkstra();
	
	int sum = 0;
	for (int i = 1; i <= N; i++){
		sum += track[i].size();
	}
	printf("%d\n",sum);
	for (int i = 1; i <= N; i++){
		for (int j = 0; j < track[i].size(); j++){
			printf("%d %d\n",track[i][j],i);
		}
	}
}
