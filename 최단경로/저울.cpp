#include<stdio.h>
using namespace std;
int N, M, who;
int adj[102][102];
int min_num = 100000;

int min(int x, int y){
	return x > y ? y : x;
}

void print(){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(){
	scanf("%d",&N);
	scanf("%d",&M);
	for (int i = 0; i < M; i++){
		int from, to, cost;
		scanf("%d%d",&from,&to);
		adj[from][to] = 1;
	}
	for (int k = 1; k <= N; k++){
		for (int i = 1; i <= N; i++){
			if (i == k){
				adj[k][i] = 1;
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
	
	for (int i = 1; i <= N; i++){
		int cnt = 0;
		for (int j = 1; j <= N; j++){
			if (adj[i][j] == 0 && adj[j][i] == 0){
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	
    return 0;
}
