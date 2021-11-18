#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
int N, M;
vector<int> input, tree, lazy;

int init(int node, int start, int end){
	if (start == end){
		return tree[node] = input[start];
	}
	int mid = (start + end) / 2;
	int left = init(node*2,start,mid);
	int right = init(node*2+1,mid+1,end);
	return tree[node] = left ^ right;
}

void lazy_update(int node, int start, int end){
	if (lazy[node] != 0){
		int time = (end - start + 1);
		if (time % 2 == 1){
			tree[node] = tree[node] ^ lazy[node];
		}
		if (start != end){
			lazy[node*2] = lazy[node*2] ^ lazy[node];
			lazy[node*2+1] = lazy[node*2+1] ^ lazy[node]; 
		}
		lazy[node] = 0;
	}
}

void update(int node, int start, int end, int left, int right, int diff){
	lazy_update(node,start,end);
	if (left > end || right < start){
		return;
	}
	if (left <= start && end <= right){
		int time = (end - start + 1);
		if (time % 2 == 1){
			tree[node] = tree[node] ^ diff;
		}
		if (start != end){
			lazy[node*2] = lazy[node*2] ^ diff;
			lazy[node*2+1] = lazy[node*2+1] ^ diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(node*2,start,mid,left,right,diff);
	update(node*2+1,mid+1,end,left,right,diff);
	tree[node] = tree[node*2] ^ tree[node*2+1];
}

int sum(int node, int start, int end, int left, int right){
	lazy_update(node,start,end);
	if (start > right || left > end){
		return 0;
	}
	if (left <= start && end <= right){
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(node*2,start,mid,left,right) ^ sum(node*2+1,mid+1,end,left,right);
}

int main(){
	scanf("%d",&N);
	int tree_height = ceil(log2(N));
	int tree_size = 1 << (tree_height+1);
	input.resize(N+1,0);
	tree.resize(tree_size,0);
	lazy.resize(tree_size,0);
	for (int i = 0; i < N; i++){
		scanf("%d",&input[i]);
	}
	init(1,0,N-1);
	scanf("%d",&M); 
	for (int i = 0; i < M; i++){
		int a, b, c, d;
		scanf("%d%d%d",&a,&b,&c);
		if (a == 1){ // xor update 
			int d;
			scanf("%d",&d);
			update(1,0,N-1,b,c,d);
		}
		else{ // 
			printf("%d\n",sum(1,0,N-1,b,c));
		}
		
	}
	return 0;
}
