#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;
struct Site {
    int x[3],i;
} p[100001];
int N,M,A,B,C,T,res[100001],tree[100001];
vector<pi> adj[100001];
vector<int> dijkstra(int s) {
    vector<int> dist(N+1,1e9+1);
    priority_queue<pi,vector<pi>,greater<pi>> q;
    dist[s]=0;
    q.push(make_pair(dist[s],s));
    while(!q.empty()) {
        int v=q.top().second; q.pop();
        for(int i=0,to,cost;i<adj[v].size();i++) {
            to=adj[v][i].first, cost=adj[v][i].second;
            if(dist[v]+cost<dist[to]) {
                dist[to]=dist[v]+cost;
                q.push(make_pair(dist[to],to));
            }
        }
    }
    return dist;
}
bool cmp(Site A, Site B) { return A.x[0]<B.x[0]; }	// 첫번쨰 시험 기준 정렬 
bool cmp2(Site A, Site B) { return A.x[1]<B.x[1]; }	// 2번째 시험 기준 정렬 
int read(int x) {
    int ret=1e9;
    while(x>0) {
        if(tree[x]<ret)
            ret=tree[x];
        x&=(x-1);
    }
    return ret;
}
void update(int x, int val) {
    while(x && x<=N) {
        if(tree[x]>val)
            tree[x]=val;
        x += x&-x;
    }
}
int main() {
    scanf("%d%d%d%d%d",&N,&A,&B,&C,&M);
    for(int i=0,a,b,c;i<M;i++) {
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    vector< vector<int> > dist;
    dist.push_back(dijkstra(A));
    dist.push_back(dijkstra(B));
    dist.push_back(dijkstra(C));
    for (int i = 0; i < 3; i++){
    	for (int j = 1; j <= N; j++){
    		printf("%d ",dist[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
    for(int k=0;k<dist.size();k++){
    	for(int i=1;i<=N;i++){
    		p[i].x[k]=dist[k][i];
		}
	}
        
    for(int i=1;i<=N;i++) {
        p[i].i=i;
        tree[i]=1e9;
    }
    
    for (int i = 1; i <= N; i++){	// 성적과 i번 후보지 
		printf("(");
		for (int j = 0; j < 3; j++){
			printf("%d ",p[i].x[j]);
		}
		printf("), %d\n",p[i].i);
	} 
    printf("sort cmp2\n");
    sort(p+1,p+1+N,cmp2);
    
    for (int i = 1; i <= N; i++){	// 성적과 i번 후보지 
		printf("(");
		for (int j = 0; j < 3; j++){
			printf("%d ",p[i].x[j]);
		}
		printf("), %d\n",p[i].i);
	} 
	
    for(int i=1,j=1;i<=N;i++) {
        p[i].x[1]=j;
        if(i<N && p[i].x[1]!=p[i+1].x[1]) j++;
    }
    printf("erase duplicate\n");
    for (int i = 1; i <= N; i++){	// 성적과 i번 후보지 
		printf("(");
		for (int j = 0; j < 3; j++){
			printf("%d ",p[i].x[j]);
		}
		printf("), %d\n",p[i].i);
	} 
    
    sort(p+1,p+1+N,cmp);
    printf("sort cmp1 \n");
    for (int i = 1; i <= N; i++){	// 성적과 i번 후보지 
		printf("(");
		for (int j = 0; j < 3; j++){
			printf("%d ",p[i].x[j]);
		}
		printf("), %d\n",p[i].i);
	} 
    for(int i=1,j=1;i<=N;i++) {
        if(read(p[i].x[1]-1)<p[i].x[2]) res[p[i].i]=0;
        else res[p[i].i]=1;
        if(i<N && p[i].x[0]!=p[i+1].x[0]){
        	for(;j<=i;j++){
            	update(p[j].x[1], p[j].x[2]);
            	printf("tree\n");
				    for (int i = 1; i <= N; i++){
				    	printf("%d ",tree[i]);
					}
					printf("\n");
			}
		}
            
                
    }
    printf("tree\n");
    for (int i = 1; i <= N; i++){
    	printf("%d ",tree[i]);
	}
	printf("\n");
    scanf("%d",&T);
    for(int i=0,Q;i<T;i++) {
        scanf("%d",&Q);
        if(res[Q]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
