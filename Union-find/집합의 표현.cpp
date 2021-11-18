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
	
	return parent[x] = find(parent[x]); // compression ���� ���� ���� 
}

void Union(int a, int b){
	a = find(a);	// a�� ���� 
	b = find(b);	// b�� ���� 

	if (a == b){	// ������ ������ pass 
		return;
	}
	// a�� b���� ��ٸ� 
	if (level[a] > level[b]){
		swap(a,b);	// ���� ����	
	}
	// a�� ��Ʈ�� b�� �ǵ��� 
	parent[a] = b;
	
	// ���̰� ���� Ʈ������ ��ģ�ٸ� 
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

