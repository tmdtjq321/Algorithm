#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
int N, M;
int parent[1000002]; 
int level[1000002]; 
char input[1002][1002];
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
	
	if (level[x] < level[y]){
		swap(x,y);
	}
	
	parent[y] = x;
	
	if (level[x] == level[y]){
		level[x]++;
	}
}

void gogo(int x, int y, char t){
	if (t == 'S'){
		int nx = x * M + y;
		int ny = (x+1) * M + y;
		if (find(nx) != find(ny)){
			merge(nx,ny);
			gogo(x+1,y,input[x+1][y]);
		}
	}
	else if (t == 'W'){
		int nx = x * M + y;
		int ny = x * M + y-1;
		if (find(nx) != find(ny)){
			merge(nx,ny);
			gogo(x,y-1,input[x][y-1]);
		}
	}
	else if (t == 'E'){
		int nx = x * M + y;
		int ny = x * M + y+1;
		if (find(nx) != find(ny)){
			merge(nx,ny);
			gogo(x,y+1,input[x][y+1]);
		}
	}
	else{
		int nx = x * M + y;
		int ny = (x-1) * M + y;
		if (find(nx) != find(ny)){
			merge(nx,ny);
			gogo(x-1,y,input[x-1][y]);
		}
	}
	
}

int main(){
	scanf("%d%d",&N,&M);
	for (int i = 0; i < N*M; i++){
		parent[i] = i;
		level[i] = 1;
	}
	for (int i = 0; i < N; i++){
		scanf("%s",input[i]);
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			gogo(i,j,input[i][j]);
		}
	}
	for (int i = 0; i < N*M; i++){
		find(i);
		s.insert(parent[i]);
	}
	
	printf("%d\n",s.size());
	
	return 0;
}
