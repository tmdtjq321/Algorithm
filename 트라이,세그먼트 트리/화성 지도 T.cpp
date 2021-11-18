#include <cstdio>
#include <algorithm>
#define MAX_N 10000
#define MAX_Y 30000
using namespace std;
struct m {
    int x, y1, y2, z;
};
bool cmp(m a, m b) {
    return a.x < b.x;
}
int n, seg[4 * MAX_Y], a, b, c, d, cnt[4 * MAX_Y], last, res;
m arr[2 * MAX_N];
void update(int lo, int hi, int val, int node, int x, int y) {
    if (y < lo || hi < x) { // 영역 제외 
    	return;
	}
    if (lo <= x&&y <= hi){ // 영역에 포함 
    	cnt[node] += val;
    	printf("s e %d %d %d %d\n",x,y,cnt[node],node);
	} 
    else {
        int mid = (x + y) >> 1;
        update(lo, hi, val, node * 2, x, mid);
        update(lo, hi, val, node * 2 + 1, mid + 1, y);
    }
    if (cnt[node])seg[node] = y - x + 1;
    else {
        if (x == y)seg[node] = 0;
        else seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        arr[i] = { a,b,d - 1,1 };
        arr[i + n] = { c,b,d - 1,-1 };
    }
    sort(arr, arr + 2 * n, cmp); // x로 정렬 
    for (int i = 0; i < 2 * n; i++) {
        if (i) { // 0은 제외 
            int dx = arr[i].x - last;
            res += dx*seg[1];
        }
        update(arr[i].y1, arr[i].y2, arr[i].z, 1, 0, MAX_Y);
        printf("seg %d\n",seg[1]);
        last = arr[i].x;
    }
    printf("%d\n", res);
    return 0;
}
