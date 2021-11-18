#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string> 
#include <vector>
using namespace std;
int N;
struct student{
	string s;
	int a,b,c;
};
bool cmp(student _a, student _b){
	if (_a.a == _b.a){
		if (_a.b == _b.b){
			if (_a.c == _b.c){
				return (_a.s < _b.s);
			}
			return (_a.c > _b.c);  
		}
		return (_a.b < _b.b);
	}
	return (_a.a > _b.a);
}
int main() {
	ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    vector<student> V(N+1);
    for (int i = 0; i < N; i++){
    	cin >> V[i].s >> V[i].a >> V[i].b >> V[i].c;
	}
	sort(V.begin(),V.end(),cmp);
	for (int i = 0; i < N; i++){
		cout << V[i].s << "\n";
	}
    return 0;
}
