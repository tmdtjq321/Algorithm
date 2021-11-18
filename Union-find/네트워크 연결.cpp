#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int T, N;
int dist[20002];
int par[20002];

int find(int x){
	if (par[x] == x){
		return x;
	}
	int tmp = find(par[x]);
	dist[x] += dist[par[x]];
	par[x] = tmp;
	
	return tmp;	
}

void merge(int x, int y){
	dist[x] = abs(x-y) % 1000;
	par[x] = y;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for (int i = 1; i <= N; i++){
			dist[i] = 0;
			par[i] = i;
		}
		char t;
		while(1){
			scanf("%c",&t);
			if (t == 'O'){
				break;
			}
			if (t == 'E'){
				int n;
				scanf("%d",&n);
				find(n);
				printf("%d\n",dist[n]);
			}
			else if (t == 'I'){
				int x, y;
				scanf("%d%d",&x,&y);
				merge(x,y);
			}
		}
		
	}
	return 0;
}
