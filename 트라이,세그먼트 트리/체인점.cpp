#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

struct Info{
    int x, y, z, i;
    Info(){ x = 0, y = 0, z = 0, i = 0; }
    bool operator < (const Info &rhs) const{
        if(x == rhs.x){
            if (y == rhs.y) return z > rhs.z;
            return y > rhs.y;
        }
        return x < rhs.x;
    }
} A[100001];

struct SegmentTree{
    int tree[400010];
    const int INF = 1<<29;
    SegmentTree(){
        for (int i=0; i<400010; i++) tree[i] = INF;
    }
    int update(int node, int begin, int end, int index, int val){
        if (index < begin || end < index) return tree[node];
        if (begin == end) return tree[node] = val;
        int mid = (begin + end) >> 1;
        int v1 = update(node*2, begin, mid, index, val);
        int v2 = update(node*2+1, mid+1, end, index, val);
        return tree[node] = min(v1, v2);
    }
    int query(int node, int begin, int end, int left, int right){
        if (right < begin || end < left) return INF;
        if (left <= begin && end <= right) return tree[node];
        int mid = (begin + end) >> 1;
        int v1 = query(node*2, begin, mid, left, right);
        int v2 = query(node*2+1, mid+1, end, left, right);
        return min(v1, v2);
    }
    void print(){
    	for (int i = 1; i <= 17; i++){
    		printf("%d ",tree[i]);
		}
		printf("\n");
	}
} seg;

struct Edge{
    int to; lld w;
    Edge(int to_, lld w_){ to = to_; w = w_; }
};

struct Node{
    int u; lld d;
    Node(int u_, lld d_){ u = u_; d = d_; }
    bool operator < (const Node &other) const{
        return d > other.d;
    }
};

vector<lld> D, E, F;
int N, M, T;
int X, Y, Z;
vector<lld> U, V, W;
vector<Edge> adj[100001];
const lld llINF = 1LL<<60;
bool ans[100001];

void dijkstra(int start, vector<lld> &dist){
    dist.resize(N+1);
    dist[0] = 0;
    for (int i=1; i<=N; i++) dist[i] = llINF;
    dist[start] = 0;
    priority_queue<Node> pq;
    pq.push(Node(start, 0));
    while (!pq.empty()){
        int u = pq.top().u;
        lld dist_u = pq.top().d;
        pq.pop();
        if (dist[u] < dist_u) continue;
        for (unsigned int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].to;
            lld dist_v = dist_u + adj[u][i].w;
            if (dist_v < dist[v]){
                dist[v] = dist_v;
                pq.push(Node(v, dist_v));
            }
        }
    }
}

inline int getIndex(vector<lld> &vec, lld val){
    return lower_bound(vec.begin(), vec.end(), val) - vec.begin();
}

void solve(){
    sort(A+1, A+N+1);
    for (int i=1; i<=N; i++){
        printf("(%d %d %d %d)\n",A[i].x,A[i].y,A[i].z,A[i].i);
    }
    for (int i=1; i<=N; i++){
    	printf("%d %d\n",seg.query(1, 1, N, 1, A[i].y-1),A[i].z);
        if (seg.query(1, 1, N, 1, A[i].y-1) >= A[i].z) ans[A[i].i] = 1;
        seg.update(1, 1, N, A[i].y, min(A[i].z, seg.query(1, 1, N, A[i].y, A[i].y)));
        seg.print();
    }
}

void query(){
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        cout << (ans[n] ? "YES" : "NO") << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    cin >> X >> Y >> Z;
    cin >> M;
    for (int num = 0; num < M; num++){
        int u, v; lld w;
        cin >> u >> v >> w;
        adj[u].push_back(Edge(v, 1LL*w));
        adj[v].push_back(Edge(u, 1LL*w));
    }

    dijkstra(X, U);
    dijkstra(Y, V);
    dijkstra(Z, W);
    for (int i=1; i<=N; i++){
        D.push_back(U[i]);
        E.push_back(V[i]);
        F.push_back(W[i]);
    }
    sort(D.begin(), D.end());
    sort(E.begin(), E.end());
    sort(F.begin(), F.end());
    unique(D.begin(), D.end());
    unique(E.begin(), E.end());
    unique(F.begin(), F.end());
		
    for (int i=1; i<=N; i++){
        A[i].x = 1+getIndex(D, U[i]);
        A[i].y = 1+getIndex(E, V[i]);
        A[i].z = 1+getIndex(F, W[i]);
        A[i].i = i;
    }

    solve();
    query();
}
