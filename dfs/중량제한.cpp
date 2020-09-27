#include<stdio.h>
#include<vector> //array + list
#include<string.h>
using namespace std;

struct pt{
  int t,v;
};
vector<pt> V[10005];
int N, M, s, e;
int visit[10005];
int max_num = 0;
int left = 0;
int right = 1000000000;

int go(int start, int mid){
	printf("in %d\n",start);
	visit[start] = 1;
	if (start == e){	
		return 1;
	}
	
	for (int i = 0; i < V[start].size(); i++){
		if (visit[V[start][i].t] == 0 && mid <= V[start][i].v){ // ㅡ방문하지 않은 노드라면                 
			if(go(V[start][i].t,mid) == 0){
				continue;
			}
			else{
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d%d",&N, &M);
	for(int i=0;i<M;i++){
    	int from,to,val;
    	scanf("%d%d%d",&from,&to,&val);
    	V[from].push_back({to,val});
    	V[to].push_back({from,val});
  	}
  	scanf("%d%d",&s,&e);
  	int ans;
	while(left <= right){
		int mid = (left + right) / 2;
		printf("go %d\n",mid);
		if (go(s,mid) == 1){
			ans = mid;
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
		for (int i = 0; i <= N; i++){
			visit[i] = 0;
		}
	}
	printf("%d",ans);

   	return 0;
}

//1 (2,4) (3,3) (4,2)
//2 (2,4) (3,3) (4,2)
//3 (2,4) (3,3) (4,2)
//4 (2,4) (3,3) (4,2)

