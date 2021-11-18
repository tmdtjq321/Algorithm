#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
int N, M;
vector<ll> tree,input;

ll sum(int node){
	ll res = 0;
	while(node > 0){
		res += tree[node];
		node -= (node&-node);
	}
	return res;
}

void update(int node, ll diff){
	while(node < tree.size()){
		tree[node] += diff;
		node += (node&-node);
	}
}

int main(){
	scanf("%d%d",&N,&M);  
	tree.resize(N+1);
	input.resize(N+1);
	for (int i = 0; i < M; i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if (a == 0){
			if (b < c){
				printf("%lld\n",sum(c)-sum(b-1));
			}
			else{
				printf("%lld\n",sum(b)-sum(c-1));
			}
		}
		else{
			update(b,(ll)c-input[b]);
			input[b] = c;
		}
	}
	return 0;
}
