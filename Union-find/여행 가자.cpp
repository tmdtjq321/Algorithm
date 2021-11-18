#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int N, M;
int graph[202][202];
int level[202];
int parent[202];
int visit[202];

void printd(){
	for (int i = 1; i <= N; i++){
		printf("%d ",visit[i]);
	}
	printf("\n");
}

void print(){
	for (int i = 1; i <= N; i++){
		printf("%d ",parent[i]);
	}
	printf("\n");
}

int find(int x){
	if (parent[x] == x){
		return x;
	}
	
	return parent[x] = find(parent[x]); // compression 조상 노드로 갱신 
}

void Union(int a, int b){
	a = find(a);	// a의 조상 
	b = find(b);	// b의 조상 

	if (a == b){	// 조상이 같으면 pass 
		return;
	}
	// a가 b보다 깊다면 
	if (level[a] > level[b]){
		swap(a,b);	// 조상 변경	
	}
	// a의 루트가 b가 되도록 
	parent[a] = b;
	
	// 깊이가 같은 트리끼리 합친다면 
	if (level[a] == level[b]){
		++level[b];
	} 
}


int main(){
	scanf("%d%d",&N,&M);
	for (int i = 1; i <= N; i++){
		parent[i] = i;
		level[i] = 1;
	}
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			scanf("%d",&graph[i][j]);
			if (graph[i][j] == 1){
				Union(i,j);
			}
		}
	}
	for (int i = 1; i <= N; i++){
		find(i);
	}
	print();
	for (int i = 0; i < M; i++){
		int t;
		scanf("%d", &t);
		visit[t] = parent[t];
	}
	printd();
	bool flag = false;
	int now = 0;
	for (int i = 1; i <= N; i++){
		if (visit[i] != 0){
			if (now == 0){
				now = visit[i];
			}
			else{
				if (now != visit[i]){
					flag = true;
				}
			}
		}
	}
	if (flag){
		printf("NO");
	}
	else{
		printf("YES");
	}
	
	
	return 0;
}

