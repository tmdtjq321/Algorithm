#include<stdio.h>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;
typedef long long ll;
const int MAX = 1000000;
int N, M;
int input[MAX+2];

ll init(vector<ll> &tree, int node, int start, int end){
	if (start == end){
		return tree[node] = input[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(tree,node*2,start,mid) + init(tree,node*2+1,mid+1,end);
}

void add(vector<ll> &tree, int node, int start, int end, int index, ll diff){
	if (!(start <= index && index <= end)){
		return;
	}
	tree[node] += diff;
	if (start != end){
		int mid = (start + end) / 2;
		add(tree,node*2,start,mid,index,diff);
		add(tree,node*2+1,mid+1,end,index,diff);
	}
}

void update(vector<ll> &tree, int node, int start, int end, ll val){
	int mid = (start + end) / 2;
	if(start != end){
		if (tree[node*2] >= val){	// Å©¸é ¿ÞÂÊ 
			update(tree,node*2,start,mid,val);
			tree[node]--;
		}
		else{
			val -= tree[node*2];
			update(tree,node*2+1,mid+1,end,val);
			tree[node]--;
		}
	}
	else{ // leaf
		printf("%d\n",start);
		input[start]--;
		tree[node]--;
	}
}

int main(){
	scanf("%d",&N);
	int tree_height = ceil(log2(MAX));
	int tree_size = 1 << (tree_height+1);
	vector<ll> tree(tree_size);
	init(tree,1,1,MAX);
	for (int i = 0; i < N; i++){
		int a;
		ll b;
		scanf("%d%lld",&a,&b);
		if (a == 2){
			ll c;
			scanf("%lld",&c);
			if (c < 0){continue;}
			input[b] = c;
			add(tree,1,1,MAX,b,c);
		}
		else{
			update(tree,1,1,MAX,b);
		}
	}
	
	return 0;
} 
