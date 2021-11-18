#include<stdio.h>
#include<vector>
#include<math.h>
#include<limits>
using namespace std;
typedef long long ll;
int N, M;

const long long MAX = std::numeric_limits<long long>::max();

ll min(ll x, ll y){
	return x > y ? y : x;
}

ll init(vector<ll> &tree,vector<ll> &input,int node, int start, int end){
	if (start == end){
		return tree[node] = input[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = min(init(tree,input,node*2,start,mid),init(tree,input,node*2+1,mid+1,end));
}

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right){
	if (end < left || right < start){
		return MAX;
	}
	if (left <= start && end <= right){
		return tree[node];
	}
	if (start != end){
		int mid = (start + end) / 2;
		return min(sum(tree,node*2,start,mid,left,right),sum(tree,node*2+1,mid+1,end,left,right));
	}
	else{
		return tree[node];
	}	
	
}

int main(){
	scanf("%d%d",&N,&M);
	int tree_height = (int)ceil(log2(N));
	int tree_size = 1 << (tree_height+1);
	printf("size %d %d\n",tree_height,tree_size);
	vector<ll> input(N+1);
	vector<ll> tree(tree_size);
	for (int i = 0; i < N; i++){
		scanf("%lld",&input[i]);
	}
	init(tree,input,1,0,N-1);
	
	for (int i = 0; i < M; i++){
		int a, b;
		scanf("%d%d",&a,&b);
		printf("%lld\n",sum(tree,1,0,N-1,a-1,b-1));
	}
	return 0;
} 
