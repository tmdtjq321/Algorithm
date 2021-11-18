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
vector<int> gogo;
vector<int> back;

void dijkstra(int s){
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
			int cost = v[cur][i].w + val;
			if (dist[des] > cost){
				dist[des] = cost;
				pq.push({des,cost});
			}
		}
	}
	
	
}

int main(){
	scanf("%d%d%d",&N, &M, &T);
	for (int i = 0; i < M; i++){
		int from, to, w;
		scanf("%d%d%d",&from,&to,&w);
		v[from].push_back({to,w});
	}
	
	for (int i = 1; i <= N; i++){
		dijkstra(i);
		if (i == T){
			for (int j = 1; j <= N; j++){
				if (j == T){
					continue;
				}
				back.push_back(dist[j]);
			}
		}
		else{
			gogo.push_back(dist[T]);
		}
	}
	int max_num = 0;
	for (int i = 0; i < N-1; i++){
		int sum = back[i] + gogo[i];
		if (sum > max_num){
			max_num = sum;
		}
	}
	printf("%d\n",max_num);
	
	return 0;
}
