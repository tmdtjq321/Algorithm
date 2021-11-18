#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int N, M;
vector<int> v[32005];
int idg[32005];	// �� ����Ű�� ����� �� 
queue<int> Q;

void bfs(){
	while(!Q.empty()){
		int cur = Q.front();
		printf("%d ",cur);
		Q.pop();
		for (int i = 0; i < v[cur].size(); i++){
			idg[v[cur][i]]--;
			if (idg[v[cur][i]] == 0){
				Q.push(v[cur][i]);
			} 
		}
	}
}

int main() {
	scanf("%d%d",&N,&M);
	for (int i = 0; i < M; i++){
		int x, y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		idg[y]++;
	}
	
	for (int i = 1; i <= N; i++){
		if (idg[i] == 0){
			Q.push({i});
		}
	}
	
	bfs();
	
	return 0;
}

// bfs �� ����Ű�� ��尡 ���� ��� 
// dfs ���� ����Ű�� ��尡 ���� ��� 



