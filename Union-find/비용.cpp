#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
typedef long long ll;
const ll INF = 1e9;

struct edge{
	ll s, e, w;
	edge(){}
	edge(ll _s, ll _e, ll _w){
		s = _s;
		e = _e;
		w = _w;
	}
};

bool operator<(edge a, edge b){
	return (a.w < b.w);
}

int N, M;
int par[100002];
ll level[100002];
priority_queue<edge> pq;
ll res, total;

int find(int x){
	if (par[x] == x){
		return x;
	}
	
	return par[x] = find(par[x]);
}

int main() {
    scanf("%d%d",&N,&M);
    for (int i = 1; i <= N; i++){
    	par[i] = i;
    	level[i] = 1;
	}
    for (int i = 0; i < M; i++){
    	struct edge t;
    	scanf("%d%d%d",&t.s,&t.e,&t.w);
    	pq.push(t);
    	total += t.w;
	}
	
	while(!pq.empty()){
		ll start = find(pq.top().s);
		ll end = find(pq.top().e);
		if (start != end){
			res += (((level[start] * level[end]) % INF) * total) % INF;
            res = res % INF;
			par[start] = end;
			level[end] += level[start];
			level[start] = 1;
		}
		total -= pq.top().w;
		pq.pop();
	}
	printf("%d",res);
    
    return 0;
}

