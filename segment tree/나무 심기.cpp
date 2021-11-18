#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;
int N;
const ll MAX = 1000000007;
const int SIZE = 200002;
vector<ll> tree(SIZE);
vector<ll> ltree(SIZE);

ll sum(int node){
	ll res = 0;
	while(node > 0){
		res += tree[node];
		node -= (node &-node);
	}
	return res;
}

void update(int node, ll diff){
	while(node < tree.size()){
		tree[node] += diff;
		node += (node&-node);
	}
}

ll lsum(int node){
	ll res = 0;
	while(node > 0){
		res += ltree[node];
		node -= (node&-node);
	}
	return res;
}

void lupdate(int node, ll diff){
	while(node < ltree.size()){
		ltree[node] += diff;
		node += (node&-node);
	}
}

int main(){
	scanf("%d",&N);
	ll ans = 1;
	for (int i = 0; i < N; i++){ 
		ll t;
		scanf("%lld",&t);
        t += 1;
		int left_tree = lsum(t-1);	// 왼쪽 나무 개수 
		int right_tree = lsum(SIZE)-lsum(t); // 오른쪽 나무 개수 
		ll left_distance = ((left_tree * t) - sum(t-1)) % MAX; // 왼쪽 나무들과의 거리 
		ll right_distance = ((sum(SIZE)-sum(t)) - (right_tree * t)) % MAX; // 오른쪽 나무들과의 거리 
		ll distance = (left_distance+right_distance) % MAX;
		lupdate(t,1);
		update(t,t);
		if (i != 0){
			ans = (ans * distance) % MAX;
		}
	}
	printf("%lld",ans % MAX);
	
	return 0;
} 
