#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 0x7fffffff
using namespace std;
int V, E, S, cnt = 1;
int dist[20002];

struct pt{
	int e, w;	// 도착점 가중치 
	pt(){}
	pt(int _e, int _w){
		e=_e,w=_w;
	}
};

bool operator<(pt _a, pt _b){
	return (_a.w < _b.w);
}

vector<pt> v[20005];

void dijkstra(){
	priority_queue<pt> cur;
	dist[S]=0;
	cur.push(pt(S,0));
	while(!cur.empty()){
	  int cost = -cur.top().w;
	  int pos = cur.top().e;
	  cur.pop();
	  if(dist[pos] < cost) continue;
	  for(int i=0;i<v[pos].size();i++){
	    int des = v[pos][i].e;
	    int next = cost + v[pos][i].w;
	    if(dist[des]>next){
	      dist[des] = next;
	      cur.push(pt(des,-next));
	    }
	  }
	}
}


int main(){
	scanf("%d%d",&V,&E);
	scanf("%d",&S);	// 출발점 
	for (int i = 1; i <= V; i++){
		if (i == S){
			dist[i] = 0; 
		}
		else{
			dist[i] = MAX;
		}
	}
	
	for (int i = 1; i <= E; i++){
		int from, to, weight;
		scanf("%d%d%d",&from,&to,&weight);
		v[from].push_back((pt){to,weight});	
	}

	dijkstra();
	
	for (int i = 1; i <= V; i++){
		if (dist[i] == MAX){
			printf("INF");
		}
		else{
			printf("%d",dist[i]);
		}	
		printf("\n");
	}
	
    return 0;
}
