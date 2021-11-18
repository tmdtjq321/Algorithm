#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct line{
	int x1,y1,x2,y2;
	line(){}
	line(int _x1, int _y1, int _x2, int _y2){
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
	}
};

vector<line> V;
vector<int> par;
vector<int> lv;
int N, M;

int find(int x){
	if (par[x] == x){
		return x;
	}
	
	return par[x] = find(par[x]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	
	if (a == b){
		return;
	}
	
	if (lv[a] < lv[b]){
		swap(a,b);
	}
	
	par[b] = a;
	lv[a] += lv[b];
	lv[b] = 0;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int temp = (x1*y2+x2*y3+x3*y1);
    temp = temp - y1*x2-y2*x3-y3*x1;
    if (temp > 0) {
        return 1;
    } else if (temp < 0) {
        return -1;
    } else {
        return 0;
    }
}

int isIntersect(line x, line y) {
    pair<int, int> a(x.x1,x.y1);
    pair<int, int> b(x.x2,x.y2);
    pair<int, int> c(y.x1,y.y1);
    pair<int, int> d(y.x2,y.y2);
    int ab = ccw(a.first,a.second,b.first,b.second,c.first,c.second)*ccw(a.first,a.second,b.first,b.second, d.first,d.second);
    int cd = ccw(c.first,c.second,d.first,d.second, a.first,a.second)*ccw(c.first,c.second,d.first,d.second, b.first,b.second);
	if (ab == 0 && cd == 0) { // 교점이 있는 순간 
        if (a > b){
        	swap(a, b);
		}
        if (c > d){
        	swap(c, d);
		}
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

int main(){
	scanf("%d",&N);
	V.resize(N+1);
	par.resize(N+1);
	lv.resize(N+1);
	for (int i = 0; i < N; i++){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&V[i].x1,&V[i].y1,&V[i].x2,&V[i].y2); 
		par[i] = i;
		lv[i] = 1;
	}
	
	for (int i = 0; i < N; i++){
		for (int j = i+1; j < N; j++){
			if (isIntersect(V[i],V[j])){
				merge(i,j);				
			}
		}
	}
	
	int cnt = 0;
	int n = 0;
	for (int i = 0; i < N; i++){
		if (par[i] == i){
			cnt++;
		}
		if (lv[i] > n){
			n = lv[i];
		}
	}
	printf("%d\n",cnt);
	printf("%d",n);
	
	
	return 0;
}
