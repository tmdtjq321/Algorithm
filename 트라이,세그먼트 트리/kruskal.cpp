#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge{
	int f, t, w;
	Edge(){}
	Edge(int _f, int _t, int _w){
		f = _f;
		t = _t;
		w = _w;
	}
};

vector<Edge> m;
int par[3002];
int level[3002];
int N, M, heap_size;

int myfind(int x){
	if (x == par[x]){
		return x;
	}
	return par[x] = myfind(par[x]);	// ��� ���� 
}

bool myUnion(int a, int b){
	a = myfind(a);
	b = myfind(b);
	if (a == b){	// �θ� �����Ƿ� ����Ŭ�� �����ȴ�. 
		return false;
	}
	if (level[a] > level[b]){
		swap(a,b);
	}
	par[a] = b;
	level[b] += level[a];	// b�� a�� �θ��̹Ƿ� level ���� 
	level[b] = 1; 
	return true;
}

void Heapupdate(int node){ 
	if (m[node*2].w == 0 && m[node*2+1].w == 0){	// ���� ����̸� 
		return;
	}
	int idx = node;
	int tmp = m[node].w;
	int left_child = m[node*2].w;
	int right_child = m[node*2+1].w;
	if (left_child && tmp > left_child){	// ���� ���� ���� ���� 
		idx = node*2;
		tmp = left_child;			
	}
	if (right_child && tmp > right_child){
		idx = node*2+1;
		tmp = right_child;
	}
		
	if (node != idx){	// �θ𺸴� ���� �ڽ��� �ִٸ� ���� 
		swap(m[node],m[idx]);	
		Heapupdate(idx);	// �ٲ� ��尡 ���� �����ϴ��� Ȯ�� 
	}
}

void myHeapify(){
	for (int i = M; i >= 1; i--){
		Heapupdate(i);
	}
}

Edge myDeleteMin(){
	Edge result = m[1];
	m[1] = m[heap_size];
	m[heap_size].f = 0, m[heap_size].t = 0, m[heap_size].w = 0;
	heap_size--;
	Heapupdate(1);
	
	return result;	
}

int readGraph(){
	int res = 0;
	for (int i = 1; i <= M; i++){
		Edge cur = myDeleteMin();
		int from = cur.f, to = cur.t, w = cur.w;
		if (myUnion(from,to)){	
			res += w;
		}
	}
	return res;
}

int main(){
	scanf("%d%d",&N,&M);
	heap_size = M;
	m.resize(M+1);
	for (int i = 0; i < N; i++){
		level[i] = 1;
		par[i] = i;
	}
	for (int i = 1; i <= M; i++){
		int from, to, w;
		scanf("%d%d%d",&from,&to,&w);
		m[i] = Edge(from,to,w);
	}
	myHeapify();
	printf("%d\n",readGraph());
	
	return 0;
}
