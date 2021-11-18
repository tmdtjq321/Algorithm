#include<stdio.h>
using namespace std;
int N, M;
int adj[402][402];

int main(){
	scanf("%d%d",&N,&M);
	
	for (int i = 0; i < M; i++){
		int from, to, cost;
		scanf("%d%d",&from,&to);
		adj[from][to] = 1;
	}

    for (int k = 1; k <= N; k++){
		for (int i = 1; i <= N; i++){
			if (i == k){
				continue;
			}
			for (int j = 1; j <= N; j++){
				if (i == j || j == k){
					continue;
				}
				else if (adj[i][k] != 0 && adj[k][j] != 0){
					adj[i][j] = 1;
				}
			}
		}
	}

    int s;
	scanf("%d",&s);
	for (int i = 1; i <= s; i++){
		int from, to;
		scanf("%d%d",&from,&to);
		if (adj[from][to] == 0 && adj[to][from] == 0){
			printf("0\n");
		}
		else if (adj[from][to] != 0 && adj[to][from] == 0){
			printf("-1\n");
		}
		else if (adj[from][to] == 0 && adj[to][from] != 0){
			printf("1\n");
		}
	}
	
    return 0;
}
