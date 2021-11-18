#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm> 
using namespace std;
int T, N, M, des;
vector<int> v[1002];
int build[1002];
int idg[1002];	// 날 가르키는 노드의 수 
int time[1002];
queue<int> Q;


void bfs(){
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		for (int i = 0; i < v[cur].size(); i++){
			idg[v[cur][i]]--;
			if (build[v[cur][i]] < build[cur] + time[v[cur][i]]){
				build[v[cur][i]] = build[cur] + time[v[cur][i]];
			}
			if (idg[v[cur][i]] == 0){
				Q.push(v[cur][i]);
			} 
		}
	}
}


int main() {
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		memset(build,0,sizeof(build));
		memset(idg,0,sizeof(idg));
		memset(time,0,sizeof(time));
		memset(v,0,sizeof(v));
		for (int i = 1; i <= N; i++){
			scanf("%d",&time[i]);
		}
		for (int i = 1; i <= M; i++){
			int from, to;
			scanf("%d%d", &from, &to);
			v[from].push_back(to);
			idg[to]++;
		}
		scanf("%d", &des);
		for (int i = 1; i <= N; i++){
			if (idg[i] == 0){
				Q.push(i);
				build[i] = time[i];
			}
		}
		bfs();
		printf("%d\n",build[des]);
				
	}
	
	return 0;
}
