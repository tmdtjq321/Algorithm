#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
int N, M;
vector<int> tree, lazy;

void lazy_update(int node, int start, int end){
	if (lazy[node] != 0){
		tree[node] = (end-start+1) - tree[node];
		if (start != end){
			if (lazy[node*2]){lazy[node*2] = 0;}
			else{lazy[node*2] = 1;}
			if (lazy[node*2+1]){lazy[node*2+1] = 0;}
			else{lazy[node*2+1] = 1;}
		}
		lazy[node] = 0;
	}
}

void update(int node, int start, int end, int left, int right){
	lazy_update(node,start,end);
	if (start > right || left > end){
		return;
	}
	if (left <= start && end <= right){
		tree[node] = (end-start+1) - tree[node];
		if (start != end){
			if (lazy[node*2]){lazy[node*2] = 0;}
			else{lazy[node*2] = 1;}
			if (lazy[node*2+1]){lazy[node*2+1] = 0;}
			else{lazy[node*2+1] = 1;}
		}
		return;
	}
	int mid = (start + end) / 2;
	update(node*2,start,mid,left,right);
	update(node*2+1,mid+1,end,left,right);
	tree[node] = tree[node*2] + tree[node*2+1];
	
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
	return sum(node*2,start,mid,left,right) + sum(node*2+1,mid+1,end,left,right);
}

int main(){
	scanf("%d%d",&N,&M);
	int tree_height = ceil(log2(N));
	int tree_size = 1 << (tree_height+1);
	tree.resize(tree_size,0);
	lazy.resize(tree_size,0);	
	for (int i = 0; i < M; i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if (a == 0){ // update
			update(1,1,N,b,c);
		}
		else{ // sum
			printf("%d\n",sum(1,1,N,b,c));
		}
	}
}
