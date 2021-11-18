#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;
int N, M, Q;
vector<ll> input, tree, lazy;
ll init(int node, int start, int end){
	if (start == end){
		tree[node] = input[start];
		return tree[node];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(node*2,start,mid) + init(node*2+1,mid+1,end);
} 

void lazy_update(int node, int start, int end){
	if (lazy[node] != 0){
		tree[node] += (end-start+1) * lazy[node];
		if (start != end){
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int start, int end, int left, int right, ll diff){
	lazy_update(node,start,end);
	if (start > right || end < left){
		return;
	}
	if (left <= start && end <= right){
		tree[node] += diff * (end - start + 1);
		if (start != end){
			lazy[node*2] += diff;
			lazy[node*2+1] += diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(node*2,start,mid,left,right,diff);
	update(node*2+1,mid+1,end,left,right,diff);
	tree[node] = tree[node*2] + tree[node*2+1];
}

ll sum(int node, int start, int end, int left, int right){
	lazy_update(node,start,end);
	if (start > right || end < left){
		return 0;
	}
	if (left <= start && end <= right){
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(node*2,start,mid,left,right) + sum(node*2+1,mid+1,end,left,right);
}


int main(){
	scanf("%d%d%d",&N,&M,&Q);
	int tree_height = ceil(log2(N));
	int tree_size = 1 << (tree_height+1);
	input.resize(N+1,0);
	tree.resize(tree_size,0);
	lazy.resize(tree_size,0);
	for (int i = 1; i <= N; i++){
		scanf("%lld",&input[i]);
	}
	init(1,1,N);
	for (int i = 0; i < M+Q; i++){
		int a,b,c;
		ll d;
		scanf("%d",&a);
		if (a == 1){ // update
			scanf("%d%d%lld",&b,&c,&d);
			if (b < c){
				update(1,1,N,b,c,d);
			}
			else{
				update(1,1,N,c,b,d);
			}
		}
		else{ // sum
			scanf("%d%d",&b,&c);
			if (b < c){
				printf("%lld\n",sum(1,1,N,b,c));
			}
			else{
				printf("%lld\n",sum(1,1,N,c,b));
			}
		}
	}
	return 0;
} 
