#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int N, M;
vector<int> parent;
vector<int> level;

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
	for (int i = 0; i <=N; i++){
		parent.push_back(i);
		level.push_back(1);
	}
	while(M--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if (a == 0){
			Union(b,c);
		}
		else if (a == 1){
			if (b == c){
				printf("YES\n");
			}
			else if (find(b) == find(c)){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}
	return 0;
}

