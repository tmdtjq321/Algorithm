#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 0x7fffffff
using namespace std;
int V, E, S, A, cnt = 1;
int dist[1002];

struct pt{
	int e, w;	// ������ ����ġ 
	pt(){}
	pt(int _e, int _w){
		e=_e,w=_w;
	}
};

bool operator<(pt _a, pt _b){	// ���� 
	return (_a.w > _b.w);
}

vector<pt> v[1002];

void dijkstra(){
	priority_queue<pt> pq;
	pq.push((pt){S,0});
	while(!pq.empty()){
		int cost = pq.top().w;	// ����ġ 
		int pos = pq.top().e;	// ������ 
		pq.pop();
		if (dist[pos] < cost){ // ���� �������� ���°� ����� �� ��� �н� 
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
	scanf("%d%d",&V,&E);
	for (int i = 1; i <= E; i++){
		int from, to, weight;
		scanf("%d%d%d",&from,&to,&weight);
		v[from].push_back((pt){to,weight});	
	}
	
	scanf("%d%d",&S,&A);	// ����� ������ 
	for (int i = 1; i <= V; i++){
		if (i == S){
			dist[i] = 0; 
		}
		else{
			dist[i] = MAX;
		}
	}
	dijkstra();
	
	printf("%d",dist[A]);
	
	
	
    return 0;
}
