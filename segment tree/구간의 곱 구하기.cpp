#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int N, M, Q;

ll init(vector<ll> &tree, vector<ll> &input, int node, int start, int end){
	if (start == end){
		return tree[node] = input[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = (init(tree,input,node*2,start,mid) * init(tree,input,node*2+1,mid+1,end)) % MOD;
}

ll update(vector<ll> &tree, int node, int start, int end, int index, ll diff){
	if (!(start <= index && index <= end)){
		return tree[node];
	}
	if (start == end){
		return tree[node] = diff;
	}
	int mid = (start + end) / 2;
	return tree[node] = (update(tree,node*2,start,mid,index,diff) * update(tree,node*2+1,mid+1,end,index,diff)) % MOD;
}

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right){
	if (end < left || start > right){
		return 1;
	}
	if (left <= start && end <= right){
		return tree[node];
	}
	int mid = (start + end) / 2;
	return (sum(tree,node*2,start,mid,left,right) * sum(tree,node*2+1,mid+1,end,left,right)) % MOD;
}

int main(){
	scanf("%d%d%d",&N,&M,&Q);
	int tree_height = ceil(log2(N));
	int tree_size = 1 << (tree_height+1);
	vector<ll> tree(tree_size);
	vector<ll> input(N+1);
	for (int i = 1; i <= N; i++){
		scanf("%lld",&input[i]);
	}
	init(tree,input,1,1,N);
	for (int i = 0; i < M+Q; i++){
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		if (a == 1){
			update(tree,1,1,N,b,(ll)c);
		}
		else{
			ll ans = sum(tree,1,1,N,b,c) % MOD;
			printf("%lld\n",ans);
		}
	}
	
	return 0;
} 
