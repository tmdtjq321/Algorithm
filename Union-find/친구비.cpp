#include<stdio.h>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int N, M, T;
int parent[10002]; 
int cost[10002];

int find(int x){
	if (parent[x] == x){ 
		return x;
	}
	
	return parent[x] = find(parent[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	
	if (x == y){
		return;
	}
	
	parent[x] = y;
	
	if (cost[x] < cost[y]){
		cost[y] = cost[x];
	} 
}

int main(){
	scanf("%d%d%d",&N,&M,&T);
	for (int i = 1; i <= N; i++){
		scanf("%d",&cost[i]);
		parent[i] = i;
	}
	
	for (int i = 0; i < M; i++){
		int x, y;
		scanf("%d%d",&x,&y);
		merge(x,y);
	}
	int res = 0;
	for (int i = 1; i <= N; i++){
		if (parent[i] == i){
			res += cost[i];
		}
	}
	if (res > T){
		printf("Oh no");
	}
	else{
		printf("%d",res);
	}
	
	return 0;
}
