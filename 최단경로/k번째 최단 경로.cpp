 #include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;

struct pt{
	int e, w;
	pt(){}
	pt(int _e, int _w){
		e = _e;
		w = _w; 
	}
};

bool operator<(pt a, pt b){
	return (a.w > b.w);
}

vector<pt> v[1002];
int N, M, T, cnt;
int dist[1002];
priority_queue<int> res[1002];

void dijkstra(){
	for (int i = 2; i <= N; i++){
		dist[i] = INF;
	}
	priority_queue<pt> pq;
	pq.push({1,0});
	res[1].push(0);
	while(!pq.empty()){
		int cur = pq.top().e;
		int val = pq.top().w;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++){
			int des = v[cur][i].e;
			int cost = v[cur][i].w + val;
			if (res[des].size() < T){
				res[des].push(cost);
				pq.push({des,cost});
			}
			else if (res[des].top() > cost) {
				res[des].pop();
				res[des].push(cost);
				pq.push({des,cost});
			}
		}
	}
}

int main(){
	scanf("%d%d%d",&N,&M,&T);
	for (int i = 0; i < M; i++){
		int from,to,w;
		scanf("%d%d%d",&from,&to,&w);
		v[from].push_back({to,w});
	} 
	dijkstra();
	for (int i = 1; i <= N; i++){
		if (res[i].size() < T){
			printf("-1\n");
		}
		else{
			printf("%d\n",res[i].top());
		}
	}
	
	
	return 0;
}
