#include<stdio.h>
#include<vector>
#include<math.h>
#include<limits>
using namespace std;
typedef long long ll;
int N, M;
int mach[1000002];

void update(vector<ll> &tree, int node, int start, int end, int index){
	if (!(start <= index && index <= end)){
		return;
	}
	if (start == end){
		tree[node] = 1;
		return;
	}
	int mid = (start + end) / 2;
	update(tree,node*2,start,mid,index);
	update(tree,node*2+1,mid+1,end,index);
	tree[node] = tree[node*2] + tree[node*2+1];
}

ll sum(vector<ll> &tree, int node, int left, int right, int start, int end){
	if (left > end || right < start){
		return 0;
	}
	if (left <= start && end <= right){
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(tree,node*2,left,right,start,mid) + sum(tree,node*2+1,left,right,mid+1,end);
}

int main(){
	scanf("%d",&N);
	int tree_height = ceil(log2(N));
	int tree_size = 1 << (tree_height+1);
	vector<ll> input(N+1);
	vector<ll> tree(tree_size);
	for (int i = 1; i <= N; i++){
		scanf("%lld",&input[i]);	
	} 
	for (int i = 1; i <= N; i++){
		int t;
		scanf("%d",&t);
		mach[t] = i;
	}
	ll res = 0;
	for (int i = 1; i <= N; i++){
		res += sum(tree,1,mach[input[i]],N,1,N);
		update(tree,1,1,N,mach[input[i]]);
	}
	printf("%lld\n",res);
	
	return 0;
} 
