#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, g[100010], par[100010][22], visited[100010], h[100010], sz;
vector<vector<int>> vt;
vector<int> idx;
struct node {
    int v;
    node *l, *r;
    node(int v, node *l, node *r) :v(v), l(l), r(r) {}
    node *update(int lo, int hi, int pos) {
        if (lo <= pos&&pos <= hi) {
            if (lo == hi)return new node(v + 1, NULL, NULL);
            int mid = (lo + hi) >> 1;
            return new node(v + 1, l->update(lo, mid, pos), r->update(mid + 1, hi, pos));
        }
        return this;
    }
}*seg[100010];    //segment tree의 노드
int query(node *x, node *y, node *anc, node* ancp, int l, int r, int k) {
    if (l == r)return l;
    int cnt = x->l->v + y->l->v - anc->l->v - ancp->l->v;
    int mid = (l + r) >> 1;
    if (cnt >= k)return query(x->l, y->l, anc->l, ancp->l, l, mid, k);
    return query(x->r, y->r, anc->r, ancp->r, mid + 1, r, k - cnt);
}        //이분 탐색을 통하여 k번째 수를 담은 버킷 번호를 return
int getidx(int pos) {
    return lower_bound(idx.begin(), idx.end(), pos) - idx.begin() + 1;
}    //좌표압축 된 좌표를 return
void dfs(int here, int p, int dph) {
    seg[here] = seg[p]->update(1, sz, getidx(g[here]));
    visited[here] = 1;
    h[here] = dph;
    for (auto next : vt[here]) {
        if (!visited[next]) {
            par[next][0] = here;
            dfs(next, here, dph + 1);
        }
    }
}    //dfs를 통해 lca 전처리와 persistent segment tree를 구축
int lca(int x, int y) {
    if (h[x] > h[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if ((1 << i) <= h[y] - h[x])
            y = par[y][i];
    }
    if (x == y)return x;
    for (int i = 20; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}    //lca를 return
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &g[i]);
        idx.push_back(g[i]);
    }
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());    //가중치를 좌표 압축
    sz = idx.size();    //업데이트 될 value의 범위
    vt.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        vt[x].push_back(y);
        vt[y].push_back(x);
    }
    seg[0]= new node(0, NULL, NULL);
    seg[0]->l = seg[0]->r = seg[0];   //init
    dfs(1, 0, 0);
    for (int i = 1; i < 21; i++) {
        for (int j = 1; j <= n; j++) {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }    //lca init
    for (int i = 0; i < m; i++) {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        int anc = lca(x, y);
        printf("%d\n", idx[query(seg[x], seg[y], seg[anc], seg[par[anc][0]], 1, sz, k) - 1]);
    }    //return query
    return 0;
}
