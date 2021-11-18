#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int N, M;

vector<int> v[502];
int idg[502];
int time[502];
int build[502];
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

int main(){
	scanf("%d",&N);
	for (int i = 1; i <= N; i++){
		int T;
		scanf("%d%d",&time[i],&T);
		while (T != -1){
			v[T].push_back(i);
			idg[i]++;
			scanf("%d",&T);
		}	
	}
	for (int i = 1; i <= N; i++){
		if (idg[i] == 0){
			Q.push(i);
			build[i] = time[i];
		}
	}
	bfs();
	for (int i = 1; i <= N; i++){
		printf("%d\n",build[i]);
	}
		
	
	return 0;
}
