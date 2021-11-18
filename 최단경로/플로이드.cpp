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
}

int main(){
	scanf("%d",&N);
	scanf("%d",&M);
	for (int i = 0; i < M; i++){
		int from, to, cost;
		scanf("%d%d%d",&from,&to,&cost);
		if (adj[from][to] != 0){
			adj[from][to] = min(adj[from][to],cost);
		}
		else{
			adj[from][to] = cost;
		}
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
					if (adj[i][j] == 0){	// 처음 
						adj[i][j] = adj[i][k] + adj[k][j];
					}
					else{	// 나중 
						adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
					}
				}
			}
		}
	}
	
	print();
    return 0;
}
