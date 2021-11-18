#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
int N, M;
vector<int> input, tree;

void init(int node, int start, int end){
	if (start == end){
		tree[node] = start;
		return;
	}
	int mid = (start + end) / 2;
	init(node*2,start,mid);
	init(node*2+1,mid+1,end);
	if (input[tree[node*2]] <= input[tree[node*2+1]]){
		tree[node] = tree[node*2];
	}
	else{
		tree[node] = tree[node*2+1];
	}
}

int query(int node, int start, int end, int left, int right){
	if (left > end || right < start){
		return -1;
	}
	if (left <= start && end <= right){
		return tree[node];
	}
	int mid = (start + end) / 2;
	int m1 = query(node*2,start,mid,left,right);
	int m2 = query(node*2+1,mid+1,end,left,right);
	if (m1 == -1){
		return m2;
	}
	else if (m2 == -1){
		return m1;
	}
	else{
		if (input[m1] <= input[m2]){
			return m1;
		}
		else{
			return m2;
		}
	}
}

ll sum(int start, int end){
	int m = query(1,1,N,start,end);
	printf("m %d\n",m);
	ll area = (ll)(end-start+1) * (ll)input[m];
	if (start <= m-1){
		ll tmp = sum(start,m-1);
		if (area < tmp){
			area = tmp;
		}
	}
	if (end >= m+1){
		ll tmp = sum(m+1,end);
		if (area < tmp){
			area = tmp;
		}
	}
	return area;
}

int main(){
	while(1){
		scanf("%d",&N);
		if (N == 0){
			break;
		}
		int tree_height = ceil(log2(N));
		int tree_size = 1 << (tree_height+1);
		input.resize(N+1,0);
		tree.resize(tree_size,0);
		for (int i = 1; i <= N; i++){
			scanf("%d",&input[i]);
		}
		init(1,1,N);
		printf("%d\n",query(1,1,N,3,4));
		for (int i = 1; i < tree.size(); i++){
			printf("%d ",tree[i]);
		} 
		printf("\n");
		
		printf("%lld\n",sum(1,N));
	}
	
	return 0;
}
