#include<stdio.h>
#include<queue>
#include<vector>
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

bool operator<(pt _a, pt _b){	// 작은값으로 반환 
	return (_a.w > _b.w);
}

int dist[20002];
vector<pt> v[20002];
int N, M, max_num, cnt, ans;

int max(int a, int b){
	return a > b ? a : b;
}

void dijkstra(){
	priority_queue<pt> pq;
	pq.push({1,0});
	while(!pq.empty()){
		pt cur = pq.top();
		pq.pop();
		int ar = cur.e;
		int val = cur.w;
		if (dist[ar] < val){
			continue;
		}
		for (int i = 0; i < v[ar].size(); i++){
			int des = v[ar][i].e;
			int cost = v[ar][i].w + dist[ar];
			if (dist[des] > cost){
				dist[des] = cost;
				max_num = max(max_num,cost);
				pq.push((pt){des,cost});				
			}
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for (int i = 2; i <= N; i++){
		dist[i] = INF;
	}
	for (int i = 0; i < M; i++){
		int from, to;
		scanf("%d%d",&from,&to);
		v[from].push_back((pt){to,1});
		v[to].push_back((pt){from,1});
	}
	dijkstra();
	for (int i = 1; i <= N; i++){
		if (ans == 0 && max_num == dist[i]){
			ans = i;
		}
		if (max_num == dist[i]){
			cnt++;
		}
	}
	
	printf("%d %d %d",ans,dist[ans],cnt);
	
	return 0;
}
