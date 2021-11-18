#include<stdio.h>
using namespace std;
int N, M;
int parent[100002]; 
int dist[100002];

int find(int x){
	if (parent[x] == x){
		return x;
	}
	
	int tmp = find(parent[x]);
	dist[x] += dist[parent[x]]; 
	return parent[x] = tmp;;
}

int main(){
	while(1){
		scanf("%d %d",&N,&M);
		if (N == 0 && M == 0){
			break;
		}
		for (int i = 1; i<= N; i++){
			parent[i] = i;
			dist[i] = 0;
		}
		
		while(M--){
			char T;
			scanf(" %c",&T);
            int a,b,w;
			scanf("%d %d",&a,&b);            
			if (T == '!'){
				scanf("%d",&w);
				int rx = find(a);
				int ry = find(b);
				if (rx != ry){
					parent[rx] = ry;
					dist[rx] = dist[b] - dist[a] + w;
				}
				
			}
			else if(T == '?'){
				if (find(a) == find(b)){
					printf("%d\n",dist[a]-dist[b]);
				}
				else{
					printf("UNKNOWN\n");
				}
			}
		}
	}

	return 0;
}
