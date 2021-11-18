#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
const int E = 65536;
int N, M;
ll ans;
vector<int> input, tree;

void update(int node, int start, int end, int index, int val){
	if (index > end || start > index){
		return;
	}
	tree[node] += val;
	if (start != end){
		int mid = (start + end) / 2;
		update(node*2,start,mid,index,val);
		update(node*2+1,mid+1,end,index,val);
	}
}

void query(int node, int start, int end, int diff){
	int mid = (start + end) / 2;
	if (start != end){
		if (tree[node*2] >= diff){
			query(node*2,start,mid,diff);
		}
		else{
			diff -= tree[node*2];
			query(node*2+1,mid+1,end,diff);
		}
	}
	else{
		ans += (ll)start;
	}
}

int main(){
	scanf("%d%d",&N,&M);  
	int tree_height = (int)ceil(log2(E));
	int tree_size = 1 << (tree_height+1);
	input.resize(N,0);
	tree.resize(tree_size,0);
	for (int i = 0; i < N; i++){
		scanf("%d",&input[i]);
	}
	int count = 0;
	int middle = (M+1)/2;
	for (int i = 0; i < N; i++){
		if (count < M){
			update(1,0,E,input[i],1);
			count++;
		}
		if (count == M){
			query(1,0,E,middle);
			update(1,0,E,input[i-M+1],-1);
			count--;
		}
	}
	printf("%lld\n",ans);
}
