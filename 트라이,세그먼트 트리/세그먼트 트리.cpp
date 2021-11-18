//세그먼트 트리
//2042
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;
//세그먼트 트리는 구간의 합을 구하기 위해 그 횟수를 lgN으로 바꾸는 방법이다.
//세그먼트 트리의 리프 노드 값들은 실제로 입력받는 row data 이다.
//세그먼트 트리는 수를 바꾸는 과정이 O(lgN) 이고, 수를 더하는 과정이 O(lgN)이다.
//원래 우리가 사용하던 방법은 수를 더하는데 N번 그리고 중간에 배열의 수를 바꾸는 과정이 M 번이라 하면 총 O(MN)번 걸린다
//M=100 이고 N=2^20 일 경우에 O(MN) = 10 000 000
//O(MlgN)은 100*20 = 2000번 이다.

/*
노드의 왼쪽 자식 번호 = node*2
노드위 오른쪽 자식 번호 = node*2+1
*/
//트리 초기화
ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end){
    if(start == end)
        return tree[node]=arr[start];
    int mid = (start+end) / 2;
    return tree[node] = init(arr,tree,node*2,start,mid) + init(arr, tree, node*2+1,mid+1,end); //dfs
}

//트리의 리프노드 값을 갱신한다.
void update(vector<ll> &tree, int node, int start, int end, int index, ll diff){
    if(!(start<=index && index <= end)) //만약에 index 값이 start 와 end 사이에 없으면 리턴.
        return;
    tree[node]+=diff; //diff 는 원래 arr의 값에서 새로 변화한 값을 의미한다.
    if(start!=end){
        int mid = (start + end) /2;
        update(tree, node*2,start,mid,index,diff); //왼쪽자식
        update(tree, node*2+1,mid+1,end,index,diff); //오른쪽자식
    }
}
ll sum(vector<ll> &tree, int node, int start, int end, int left, int right){
    //[left,right] 와 [start,end] 가 겹치지 않는 경우 -> 즉 구간 합을 구하는 범위와 상관없는 경우
    if(left>end || right<start) return 0;
    //[left,right] 가 [start,end]를 완전히 포함하는 경우 -> 즉 구하고자 하는 구간합 구간에 포함
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    //[start,end]가[left,right]를 완전히 포함하는 경우 -> 즉 구하고자 하는 구간 합 범위보다는 크지만 그 내부에 구하고자 하는 구간 합 범위가 있는 경우
    return sum(tree,node*2,start,mid,left,right)+sum(tree,node*2+1,mid+1,end,left,right);
}
int main(){
    int n;
    scanf("%d",&n);
    int tree_height = (int)ceil(log2(n));
    int tree_size = 1<<(tree_height+1);
    printf("%d\n",tree_height);
    vector<ll> tree(tree_size);
    vector<ll> arr(n+1);
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    init(arr,tree,1,0,n-1);
    //3 -> 10
    update(tree, 1, 0, n-1, 3, 10-tree[3]);
    //2~7
    printf("%lld",sum(tree, 1, 0, n-1, 2,7));
    return 0;
}
//fenwick tree
#include<stdio.h>
#include<vector>
using namespace std;
typedef long long ll;
ll sum(vector<ll> &tree, int i){
	ll ans = 0;
	while(i>0){
	  ans+=tree[i];
	  i-=(i&-i);
	}
	return ans;
}
void update(vector<ll> &tree, int i, ll diff){
	while(i<tree.size()){
	  tree[i]+=diff;
	  i+=(i&-i);
	}
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	vector<ll> arr(n+1);
	vector<ll> tree(n+1);
	for(int i=1;i<=n;i++){
	  scanf("%lld",&arr[i]);
	  update(tree,i,arr[i]);
	}
	m+=k;
	while(m--){
	  int num;
	  scanf("%d",&num);
	  if(num == 1){
	    int index;
	    ll val;
	    scanf("%d%lld",&index,&val);
	    ll diff = val - arr[index];
	    arr[index] = val;
	    update(tree,index,diff);
	  }
	  else if(num == 2){
	    int left, right;
	    scanf("%d%d",&left,&right);
	    printf("%lld\n",sum(tree,right)-sum(tree,left-1));
	  }
	}
	return 0;
}
// lazy 
#include<bits/stdc++.h>
using namespace std;
#define LL long long
vector<LL> v, tree, lazy;
int n, m, k;
LL init(int node, int s, int e)
{
    if (s == e) return tree[node] = v[s];
    return tree[node] = init(2 * node, s, (s + e) / 2) +
        init(2 * node + 1, (s + e) / 2 + 1, e);
}
void update_lazy(int node, int s, int e)
{
    if (lazy[node] != 0) {
        tree[node] += (e - s + 1) * lazy[node];
        // leaf가 아니라면
        if (s != e) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update_range(int node, int l, int r, int s, int e, LL diff)
{
    update_lazy(node, s, e);
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        tree[node] += (e - s + 1) * diff;
        if (s != e) {
            lazy[2 * node] += diff;
            lazy[2 * node + 1] += diff;
        }
        return;
    }
    update_range(2 * node, l, r, s, (s + e) / 2, diff);
    update_range(2 * node + 1, l, r, (s + e) / 2 + 1, e, diff);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
LL sum(int node, int l, int r, int s, int e)
{
    update_lazy(node, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[node];
    return sum(2 * node, l, r, s, (s + e) / 2) +
        sum(2 * node + 1, l, r, (s + e) / 2 + 1, e);
}
int main()
{
    cin.tie(0);
    scanf("%d %d %d", &n, &m, &k);
    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h + 1);
    v.resize(n, 0);
    tree.resize(tree_size, 0);
    lazy.resize(tree_size, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }
    init(1, 0, n - 1);
    for (int i = 0; i < m + k; i++) {
        int a;
        scanf("%d", &a);
        if (a == 1) {
            int b, c;
            LL d;
            scanf("%d %d %lld", &b, &c, &d);
            update_range(1, b - 1, c - 1, 0, n - 1, d);
        }
        else {
            int b, c;
            scanf("%d %d", &b, &c);
            printf("%lld\n", sum(1, b - 1, c - 1, 0, n - 1));
        }
    }
    return 0;
}
