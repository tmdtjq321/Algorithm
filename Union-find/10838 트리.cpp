#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
int N, M;
int color[100010];
int parent[100010];
int lca[100010];

int getlca(int x,int y,int c){
	if (x == y){
		return x;
	}
	int cnt = 0;
	while (x && cnt < 1000){
		lca[x] = c;
		x = parent[x];
		cnt++;
	}
	cnt = 0;
	while (y && cnt < 1000){
		if (lca[y] == c){
			return y;
		}
		y = parent[y];
		cnt++;
	}
	return 0;
}

int main(){
	scanf("%d%d",&N, &M);
	
	for (int i = 1; i <= M; i++){
		int t,a,b;
		scanf("%d%d%d",&t,&a,&b);
		if (t == 1){
			int c;
			scanf("%d",&c);
			int point = getlca(a,b,i);
			while(a != point){
				color[a] = c;
				a = parent[a];
			}
			while(b != point){
				color[b] = c;
				b = parent[b];
			}
			for (int j = 0; j < N; j++){
				printf("%d ",parent[j]);
			}
			printf("\n");
			for (int j = 0; j < N; j++){
				printf("%d ",color[j]);
			}
			printf("\n");
		}
		else if (t == 2){
			parent[a] = b;
		}
		else{
			set<int> st;
			int point = getlca(a,b,i);
			while(a != point){
				st.insert(color[a]);
				a = parent[a];
			}
			while(b != point){
				st.insert(color[b]);
				b = parent[b];
			}
			printf("%d\n",st.size());
		}
	}
	
	return 0;
}
