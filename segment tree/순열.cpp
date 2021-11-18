#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
int N, M;
int init(vector<int> &tree, int node, int start, int end){
	if (start == end){
		return tree[node] = 1;
	}
	int mid = (start + end) / 2;
	return tree[node] = init(tree,node*2,start,mid) + init(tree,node*2+1,mid+1,end);
}

void query(vector<int> &tree, vector<int> &ans, int node, int start, int end, int val, int i){
	int mid = (start + end) / 2;
	if (start != end){
		if (tree[node*2] < val){
			val -= tree[node*2];
			query(tree,ans,node*2+1,mid+1,end,val,i);
			tree[node]--;
		}
		else{
			query(tree,ans,node*2,start,mid,val,i);
			tree[node]--;
		}
	}
	else{
		ans[start-1] = i;
		tree[node] = 0;
	}
}

int main(){
	scanf("%d",&N);
	int tree_height = (int)ceil(log2(N));
	int tree_size = 1 << (tree_height+1);
	vector<int> ans(N+1);
	vector<int> tree(tree_size);
	init(tree,1,1,N);
	for (int i = 0; i < N; i++){
		int t;
		scanf("%d",&t);
		query(tree,ans,1,1,N,t+1,i+1);
	}
	for (int i = 0; i < N; i++){
		printf("%d\n",ans[i]);
	}
}
