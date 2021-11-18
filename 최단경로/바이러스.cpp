#include <stdio.h>
int V, edge, cnt;
int adj[102][102];

int min(int x, int y){
	return x > y ? y : x;
}

int main(){
	scanf("%d",&V);
	scanf("%d",&edge);
	
	for (int i = 0; i < edge; i++){
		int from, to;
		scanf("%d%d",&from,&to);
		adj[from-1][to-1] = 1;
		adj[to-1][from-1] = 1;
	}
	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++){
			for (int k = 0; k < V; k++){
				if (adj[i][k] == 1 && adj[k][j] == 1){
					adj[i][j] = 1;
				}
				if (adj[0][k] == 1 && adj[k][j] == 1){
					adj[0][j] = 1;
					adj[j][0] = 1;
				}
			}
		}
	}

	for (int i = 1; i < V; i++){
		if (adj[0][i] != 0){
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
