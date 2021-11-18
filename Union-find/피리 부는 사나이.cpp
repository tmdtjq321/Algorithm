#include<stdio.h>
#include<set>
using namespace std;
int N, M, cnt = 1;
char input[1002][1002];
int parent[1000002];
set<int> s;

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
}

void dfs(int x, int y, char d){
	if (d == 'D'){
		int cur = x * M + y;
		int next = (x+1) * M + y;
		if (find(cur) != find(next)){
			merge(cur,next);
			dfs(x+1,y,input[x+1][y]);
		}
	}
	else if (d == 'U'){
		int cur = x * M + y;
		int next = (x-1) * M + y;
		if (find(cur) != find(next)){
			merge(cur,next);
			dfs(x-1,y,input[x-1][y]);
		}
	} 
	else if (d == 'R'){
		int cur = x * M + y;
		int next = x * M + y+1;
		if (find(cur) != find(next)){
			merge(cur,next);
			dfs(x,y+1,input[x][y+1]);
		}
	} 
	else {
		int cur = x * M + y;
		int next = x * M + y-1;
		if (find(cur) != find(next)){
			merge(cur,next);
			dfs(x,y-1,input[x][y-1]);
		}
	} 
}

int main(){
	scanf("%d%d",&N,&M);
	for (int i = 0; i< N; i++){
		scanf("%s",input[i]);
		for (int j = 0; j < M; j++){
			int t = i * M + j;
			parent[t] = t;
		}
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			dfs(i,j,input[i][j]);
		}
	}
	for (int i = 0; i < N*M; i++){
		find(i);
		s.insert(parent[i]);
	}
	
	printf("%d",s.size());
	
	return 0;
} 
