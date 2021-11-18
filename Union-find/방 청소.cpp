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
	
	return parent[x].first = find(parent[x].first); // compression ���� ���� ���� 
}

void Union(int a, int b){
	a = find(a);	// a�� ���� 
	b = find(b);	// b�� ���� 
	
	if (a == b){	// ������ ������ pass 
		if (parent[b].second - 1 < 0){ // ����� �ڽ� ��尡 �ϳ��� ���ٸ� 
			printf("SMECE\n");
		}
		else{
			parent[b].second--;
			printf("LADICA\n");
		} 
		return;
	}
	// b�� a���� ��ٸ� 
	if (level[a] > level[b]){
		swap(a,b);	// ���� ����
	}
	// a�� ��Ʈ�� b�� �ǵ��� 
	parent[a].first = b;
	
	// ���̰� ���� Ʈ������ ��ģ�ٸ� 
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

