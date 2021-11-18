#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<limits>
using namespace std;
typedef long long ll;
const ll INF = std::numeric_limits<long long>::max();
struct pt{
	int e;
	ll w;
	pt(){}
	pt(int _e, ll _w){
		e = _e;
		w = _w;
	}
};

bool operator<(pt a, pt b){
	return (a.w > b.w);
}

int N,M,T;
vector<pt> v[10002];
ll dist[10002][22];

ll min(ll x, ll y){
	return x > y ? y : x;
}

void dijkstra(){
	for (int i = 2; i <= N; i++){
		for (int j = 0; j <= T; j++){
			dist[i][j] = INF;
		}
	}
	dist[1][0] = 0;
	priority_queue<pair<pt,int>> pq;
	pq.push({{1,0},0});
	while(!pq.empty()){
		int cur = pq.top().first.e;
		ll val = pq.top().first.w;
		int time = pq.top().second;
		pq.pop();
		if (dist[cur][time] < val){
			continue;
		}
		for (int i = 0; i < v[cur].size(); i++){
			int des = v[cur][i].e;
			ll cost = v[cur][i].w + val;
			if (time <= T && dist[des][time+1] > val){
				dist[des][time+1] = val;
				pq.push({{des,val},time+1});
			}
			if (dist[des][time] > cost){
				dist[des][time] = cost;
				pq.push({{des,cost},time});
			}
		}
	}
}

int main(){
	scanf("%d%d%d",&N,&M,&T);
	for (int i = 0; i < M; i++){
		int from, to;
		ll w;
		scanf("%d%d%lld",&from,&to,&w);
		v[from].push_back({to,w});
		v[to].push_back({from,w});
	}
	dijkstra();
	
	ll res = INF;
	for (int i = 0; i <= T; i++){
		res = min(res,dist[N][i]);
	}
	printf("%lld",res);
	
	
	return 0;
}
