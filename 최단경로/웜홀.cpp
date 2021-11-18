#include<stdio.h>
#include<vector>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int T, N, M, W;
struct pt{
	int e, w;
};

int main(){
	scanf("%d",&T);
	while(T--){
		vector<pt> v[502];
		long long dist[501];
		scanf("%d%d%d",&N,&M,&W);
		for (int i = 0; i < M; i++){
			int from, to, weight;
			scanf("%d%d%d",&from,&to,&weight);
			v[from].push_back((pt){to,weight});
			v[to].push_back((pt){from,weight});
		}
		
		for (int i = 0; i < W; i++){
			int from, to, weight;
			scanf("%d%d%d",&from,&to,&weight);
			v[from].push_back((pt){to,-weight});
		}

        bool cycle = false;
		for (int i = 1; i <= N; i++){
			dist[i] = INF;	
		}
		dist[1] = 0;
		
		for (int k = 1; k <= N; k++){
			for (int i = 1; i <= N; i++){
				for (int j = 0; j < v[i].size(); j++){
					int cur = v[i][j].e;
					int cost = v[i][j].w;
					if (dist[cur] > dist[i] + cost){
						dist[cur] = cost + dist[i];
						if (k == N){
							cycle = true;
						}
					}
				}
			}
		}
		
		if (cycle){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		
		
	}
	
	return 0;
}
