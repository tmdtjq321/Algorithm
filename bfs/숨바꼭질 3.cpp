#include<stdio.h>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
const int INF = 0x7fffffff;
struct pt{
	int x,w;
	pt(){}
	pt(int _x, int _w){
		x = _x;
		w = _w;
	}
};

bool operator<(pt a, pt b){
	return (a.w > b.w);
}

int N, M, K;
int dist[100002];

bool isin(int x){
	return (x >= 0 && x <= 100000);
}

void dijkstra(){
	for (int i = 0; i <= 100000; i++){
		dist[i] = INF;
	}
	dist[N] = 0;
	priority_queue<pt> pq;
	pq.push((pt){N,0});
	while(!pq.empty()){
		int cur = pq.top().x;
		int val = pq.top().w;
		pq.pop();
		if (dist[cur] < val){
			continue;
		}
		for (int i = 0; i < 3; i++){
			int des, cost;
			if (i == 0){
				des = cur - 1;
				cost = val + 1;
			}
			else if (i == 1){
				des = cur + 1;
				cost = val + 1;
			}
			else{
				des = cur * 2;
				cost = val;
			}
			if (isin(des) && dist[des] > cost){
				dist[des] = cost;
				pq.push((pt){des,cost});
			}
		}
	}	
}
int main(){
    scanf("%d%d", &N, &M);
    dijkstra();
    printf("%d\n",dist[M]);
    
    return 0;
}
