#include<stdio.h>
#include<vector>
#include<math.h>
#include<limits>
using namespace std;
typedef long long ll;
int N, M;

ll init(vector<ll> &input, vector<ll> &tree, int node, int start, int end){
	if (start == end){
		return tree[node] = input[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(input,tree,node*2,start,mid) + init(input,tree,node*2+1,mid+1,end);
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff){
	if (!(start <= index && index <= end)){
		return;
	}
	tree[node] += diff;
	if (start != end){
		int mid = (start + end) / 2;
		update(tree,node*2,start,mid,index,diff);
		update(tree,node*2+1,mid+1,end,index,diff);
	}
}

ll sum(vector<ll> &tree, int node, int left, int right, int start, int end){
	if (start > right || left > end){
		return 0;
	}
	if (left <= start && end <= right){
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(tree,node*2,left,right,start,mid) + sum(tree,node*2+1,left,right,mid+1,end);
}


int main(){
	scanf("%d%d",&N,&M);
	int tree_height = ceil(log2(N));
	int tree_size = 1 << (tree_height+1);
	vector<ll> input(N+1);
	vector<ll> tree(tree_size);
	for (int i = 0; i < N; i++){
		scanf("%d",&input[i]);
	}
	init(input,tree,1,0,N-1);
	for (int i = 0; i < M; i++){
		int a, b, c;
		ll d;
		scanf("%d%d%d%lld",&a,&b,&c,&d);
		a--, b--, c--;
		if (a > b){swap(a,b);}
		printf("%lld\n",sum(tree,1,a,b,0,N-1));
		update(tree,1,0,N-1,c,d-input[c]);
		input[c] = d;
	}
	
	return 0;
} 
