#include<stdio.h>
#include<algorithm>
#include<vector> 
#include<queue>
#define INF 987654321
using namespace std;
int N,MD,ML;

vector<pair<int,int>> v[1002];
int dist[1002];

int main(){
	scanf("%d%d%d",&N,&ML,&MD);
	for (int i = 0; i < ML; i++){
		int from, to, val;
		scanf("%d%d%d",&from,&to,&val);
		v[from].push_back({to,val});		
	}
	for (int i = 0; i < MD; i++){
		int from, to, val;
		scanf("%d%d%d",&from,&to,&val);
		v[to].push_back({from,-val});
	}
	
	for (int i = 2; i <= N; i++){
		dist[i] = INF;
	}
	
	for (int i = 1; i <= N; i++){
		bool cycle = false;
		for (int j = 1; j <= N; j++){
			for (int k = 0; k < v[j].size(); k++){
				if (dist[j] != INF && dist[v[j][k].first] > dist[j] + v[j][k].second){
					dist[v[j][k].first] = dist[j] + v[j][k].second;
					cycle = true;
				}
			}
		}
		if (i == N){
			if (cycle){
				printf("-1");
			}
			else if (dist[N] == INF){
				printf("-2");
			}
			else{
				printf("%d",dist[N]);
			}
		}
	}
	
	
    return 0;
}
