#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;
int N, M, K;
int idx;

ll init(vector<ll> &input, vector<ll> &tree, int node, int start, int end){
	if (start == end){	// leaf node 
		return tree[node] = input[start];
	}
	int mid = (start+end) / 2;
	return tree[node] = init(input, tree, node*2, start, mid) + init(input, tree, node*2 + 1, mid+1, end);
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff){
	if (!(start <= index && index <= end)){ // ���� �� ������ 
		return;
	}
	tree[node] += diff;	// �ش� ��尡 ����ִ� ������ �� update 
	if (start == end){
		idx = start;
	}
	else { // leaf node�� �ƴϸ� 
		int mid = (start + end) / 2;
		update(tree,node*2,start,mid,index,diff);
		update(tree,node*2+1,mid+1,end,index,diff);
	}
}

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right){
	if (start > right || end < left){ // �ش� ������ ��ġ�� �κ��� �ƿ� ���� �� 
		return 0;
	}
	if (left <= start && end <= right) { // ���Ϸ��� ������ ����� ������ ���Եȴٸ� 
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(tree,node*2,start,mid,left,right) + sum(tree,node*2+1,mid+1,end,left,right);
	
} 


int main(){	
	scanf("%d%d%d",&N,&M,&K);
	int tree_height = ceil(log2(N));
	ll tree_size = 1 << (tree_height+1);
	vector<ll> input(N+1); 
	vector<ll> tree(tree_size);
	for (int i = 0; i < N; i++){
		scanf("%d",&input[i]);
	}
	init(input,tree,1,0,N-1);
	for (int i = 0; i < M+K; i++){
		ll a, b, c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if (a == 1){ // update 
			update(tree, 1, 0, N-1, b-1 ,c-input[b-1]);
			input[idx] = c;
		}
		else{ // sum 
			printf("%lld\n",sum(tree,1,0,N-1,b-1,c-1));
		}
	}
	
	
	return 0;
}
