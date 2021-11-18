#include<stdio.h>
using namespace std;
int N, M, who;
int adj[102][102];
int min_num = 100000;

int min(int x, int y){
	return x > y ? y : x;
}

int main(){
	scanf("%d%d",&N,&M);
	for (int i = 0; i < M; i++){
		int from, to;
		scanf("%d%d",&from,&to);
		adj[from][to] = 1;
		adj[to][from] = 1;
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
	
	for (int i = 1; i <= N; i++){
		int sum = 0;
		for (int j = 1; j <= N; j++){
			sum += adj[i][j];
		}
		if (sum < min_num){
			min_num = sum;
			who = i;
		}
	}
	
	printf("%d",who);
	
    return 0;
}
