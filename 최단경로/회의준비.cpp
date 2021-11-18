#include<stdio.h>
#include<algorithm>
using namespace std;
int N, M, cnt = 1;
int adj[102][102];
pair <int,int> res[102];
pair <int,int> result[102];

int max(int x, int y){
	return x < y ? y : x;
}

int min(int x, int y){
	return x > y ? y : x;
}

int main(){
	scanf("%d",&N);
	scanf("%d",&M);
	
	for (int i = 0; i < M; i++){
		int from, to;
		scanf("%d%d",&from,&to);
		adj[from][to] = 1;
		adj[to][from] = 1;
	}
    for (int k = 1; k <= N; k++){
		for (int i = 1; i <= N; i++){
			if (i == k){
				adj[i][k] = 1;
				continue;
			}
			for (int j = 1; j <= N; j++){
				if (i == j || j == k){
					continue;
				}
				else if (adj[i][k] != 0 && adj[k][j] != 0){
					if (adj[i][j] == 0){	// ó�� 
						adj[i][j] = adj[i][k] + adj[k][j];
					}
					else{	// ���� 
						adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
					}
				}
			}
		}
	}
	int max_num = 0;
    for (int i = 1; i <= N; i++){
    	if (res[i].first == 0){
			res[i].first = cnt;	// �ش� �ο��� ���ϴ� ����ȸ �׷� 
			result[cnt].second = 100000;	// �ش� ����ȸ�� ������ ��ǥ�� �Ǿ��� �� ������ �ּҰ� 
			cnt++;
		}
		max_num = 0;
    	for (int j = 1; j <= N; j++){
    		if (res[j].first == 0 && adj[i][j] != 0){
    			res[j].first = res[i].first;	
			}
			if (adj[i][j] != 0){
				max_num = max(max_num,adj[i][j]);
			}
		}
		res[i].second = max_num;	// �ش� �ο��� ��ǥ�� �� �� ������ �ִ� ��� 
		// �ش� ����ȸ�� �ּҰ�� �� 
		result[res[i].first].second = min(result[res[i].first].second,max_num);
	}
	
	cnt--;
	printf("%d\n",cnt);
	for (int i = 1; i <= N; i++){
		if (result[res[i].first].second == res[i].second){
			printf("%d\n",i);
			result[res[i].first].second = 100000;
		}
	}
	
	
    return 0;
}
