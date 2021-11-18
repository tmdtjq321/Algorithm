#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int N, M, T, cnt;

vector<int> truth;
vector<int> input[52];
int parent[52];
int level[52];

int find(int x){
	if (parent[x] == x){
		return x;
	}
	
	return parent[x] = find(parent[x]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b){
		return;
	}
	
	if (level[a] < level[b]){
		swap(a,b);
	}
	
	parent[b] = a;
	
	if (level[a] == level[b]){
		level[a]++;
	}
}

int main(){
	scanf("%d%d",&N, &M);
	
	for (int i = 1; i <= N; i++){
		parent[i] = i;
		level[i] = 1;
	}
	
	scanf("%d",&T);
	for (int i = 0; i < T; i++){
		int t;
		scanf("%d",&t);
		truth.push_back(t);
		if (T > 1){
			merge(truth[0],truth[i]);
		}
	} 
	
	for (int i = 0; i < M; i++){
		int t;
		scanf("%d",&t);
		for (int j = 0; j < t; j++){
			int tt;
			scanf("%d",&tt);
			input[i].push_back(tt);
		}
	}
	
	for (int i = 0; i < M; i++){
		int time = input[i].size();
		if (time > 1){
			for (int j = 0; j < time; j++){
				merge(input[i][0],input[i][j]);
			}	
		}
	}
	
	int p = 0;
	if (T != 0){
		p = find(truth[0]);
	}
	
	for (int i = 0; i < M; i++){
		bool isit = false;
		for (int j = 0; j < input[i].size(); j++){
			int x = find(input[i][j]);
			if (x == p){
				isit = true;
				break;
			}
		}
		if (!isit){
			cnt++;
		}	
	}
	printf("%d",cnt);	
	
	return 0;
}
