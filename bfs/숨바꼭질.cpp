#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int N,K;
int visit[100005];
queue<int> Q;

bool isin(int x){
	return x >= 0 && x < 100005;
}

void bfs(){
	while(!Q.empty()){
		int cur = Q.front();
		if (cur == K){
			return;
		}
		Q.pop();
		for (int i = 0; i < 3; i++){
			if (i == 0){
				int tx = cur - 1;
				if (isin(tx) && visit[tx] == 0){
					Q.push({tx});
					visit[tx] = visit[cur] + 1;
				}				
			}
			else if (i == 1){
				int tx = cur + 1;
				if (isin(tx) && visit[tx] == 0){
					Q.push({tx});
					visit[tx] = visit[cur] + 1;
				}				
			}
			else if (i == 2){
				int tx = cur * 2;
				if (isin(tx) && visit[tx] == 0){
					Q.push({tx});
					visit[tx] = visit[cur] + 1;
				}				
			}
		}
	}

	return;
}

int main(){
	scanf("%d%d",&N, &K);
	Q.push({N});
	bfs();
	visit[N] = 0;
	printf("%d",visit[K]);
   	return 0;
}
