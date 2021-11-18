#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int N, M, cnt = 1;
pair<int,int> parent[300005];
int level[300005];

int find(int x){
	if (parent[x].first == x){
		return x;
	}
	
	return parent[x].first = find(parent[x].first); // compression 조상 노드로 갱신 
}

void Union(int a, int b){
	a = find(a);	// a의 조상 
	b = find(b);	// b의 조상 
	
	if (a == b){	// 조상이 같으면 pass 
		if (parent[b].second - 1 < 0){ // 연결된 자식 노드가 하나도 없다면 
			printf("SMECE\n");
		}
		else{
			parent[b].second--;
			printf("LADICA\n");
		} 
		return;
	}
	// b가 a보다 깊다면 
	if (level[a] > level[b]){
		swap(a,b);	// 조상 변경
	}
	// a의 루트가 b가 되도록 
	parent[a].first = b;
	
	// 깊이가 같은 트리끼리 합친다면 
	if (level[a] == level[b]){
		++level[b];
	} 
	
	if (parent[a].second + parent[b].second - 1 < 0){
		printf("SMECE\n");
	}
	else{
		parent[b].second += parent[a].second - 1;		
		printf("LADICA\n");
	}
	
}

int main(){
	scanf("%d%d",&N,&M);
	for (int i = 1; i <= M; i++){
		parent[i].first = i;
		parent[i].second = 1;
		level[i] = 1;
	}
	for (int i = 1; i <= N; i++) { 
		int a, b;
		scanf("%d%d",&a,&b);
		Union(a,b);
	}
	return 0;
}

