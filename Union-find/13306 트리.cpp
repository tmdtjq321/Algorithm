#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int N, M;
int parent[200005];
int graph[200005];
vector<int> input[400005];
vector<bool> res;

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
	scanf("%d%d",&N,&M);
	parent[1] = 1;
	for (int i = 2; i <= N; i++){
		int t;
		scanf("%d",&t);
		graph[i] = t;
		parent[i] = i;
	}
	for (int i = 0; i < N + M -1; i++){
		int x;
		scanf("%d",&x);
		input[i].push_back(x);
		if (x == 0){	// 제거 
			int now;
			scanf("%d",&now);
			input[i].push_back(now);
		}
		else{ 		// 질의 
			int from, to;
			scanf("%d%d",&from,&to);
			input[i].push_back(from);
			input[i].push_back(to);
		}
	}
	for (int i = N + M -2; i >= 0; i--){
		if (input[i][0] == 0){	// 제거 
			int a = input[i][1];
			Union(a,graph[a]);
		}
		else{	//질의 
			int a = input[i][1];
			int b = input[i][2];
			if (find(a) == find(b)){
				res.push_back(true);
			}
			else{
				res.push_back(false);
			}
		}
	}
	int m = res.size();
	for (int i = m - 1; i >= 0; i--){
		if (res[i]){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
