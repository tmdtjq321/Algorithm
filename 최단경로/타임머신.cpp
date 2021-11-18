#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int N, M;
struct pt{
	int e, w;
};
vector<pt> v[502];
long long dist[501];
int main(){
	int a, b, c;
	bool cycle = false;
	scanf("%d%d",&N,&M);
	for (int i = 0; i < M; i++){
		int from, to, weight;
		scanf("%d%d%d",&from,&to,&weight);
		v[from].push_back((pt){to,weight});
	}
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dist[1] = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < v[j].size(); k++) {
				int cur = v[j][k].e;
				int cost = v[j][k].w;
				if (dist[j] != INF && j != cur && dist[cur] > cost + dist[j]) {
					dist[cur] = cost + dist[j]; //최소값으로 갱신 
					if (i == N){
						cycle = true;
					}
				}
			}
		}
	}	
	

	if (cycle) printf("-1");
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == INF) printf("-1\n");
			else {
				printf("%d\n",dist[i]);
			}
		}
	}
	return 0;
}
