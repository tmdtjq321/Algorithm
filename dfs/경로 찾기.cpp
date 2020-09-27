#include<stdio.h>
int N;
int graph[105][105];
int visit[105][105];
int time[105];
int cnt = 0;

bool isin(int x, int y){
	return x >=0 && y >= 0 && x < N && y < N;
}

void dfs(int x){
	if (cnt == N){
		return;
	}
	cnt++;
	for (int i = 0; i < N; i++){
		if (isin(x,i) && graph[x][i] == 1 && time[i] == 0){
			time[i] = 1;
			dfs(i);
		}
	}
	
	return;
}

int main(){
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d",&graph[i][j]);
		}
	}	
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (graph[i][j] == 1){
				dfs(i);
				cnt = 0;
			}
		}
		for (int k = 0; k < N; k++){
			visit[i][k] = time[k];
			time[k] = 0;
		}
	}	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%d ",visit[i][j]);
		}
		printf("\n");
	}
	
   	return 0;
}
