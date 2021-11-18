#include<stdio.h>
#include<algorithm>
using namespace std;
int N, M, cnt = 0;
int level[100005];
int parent[100005];

int find(int x){
	if (parent[x] == x){
		return x;
	}
	
	return parent[x] = find(parent[x]);
}

void Union(int a, int b){
	a = find(a);
	b = find(b);
	
	parent[a] = b;
}

int main(){
	scanf("%d%d",&N, &M);
	for (int i = 0; i <= N; i++){
		parent[i] = i;
		level[i] = 1;
	}
	for (int i = 1; i <= M; i++){
		int t;
		scanf("%d",&t);
		int gate = find(t);
		if (gate == 0){
			break;
		}
		else{
			cnt++;
			Union(gate,gate - 1);
		}
	}
	printf("%d\n",cnt);
	return 0;
}

