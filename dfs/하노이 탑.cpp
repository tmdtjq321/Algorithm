#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int N;
vector<pair<int,int>> v;

void recur(int n, int from, int by, int to){
	if (n == 1){
		v.push_back({from,to});
	}
	else{
		recur(n-1,from,to,by);
		v.push_back({from,to});
		recur(n-1,by,from,to);
	}
}

string add(string a, string b){
	int up = 0;
	string res = "";
	while(!a.empty() || !b.empty() || up){
		int sum = 0;
		if (!a.empty()){
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()){
			sum += b.back() - '0';
			b.pop_back();
		}
		res += (sum % 10) + '0' + up;
		up = (sum / 10);
	}
	reverse(res.begin(),res.end());
	return res;
}

int main() { 
	ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
	if (N <= 20){
		recur(N,1,2,3);
		cout << v.size() <<"\n";
		for (int i = 0; i < v.size(); i++){
			cout << v[i].first << " " << v[i].second << "\n";
		}
	}
	else{
		string num = "1";
		for (int i = 0; i < N; i++){
			num = add(num,num);
		}
		int tmp = num.back()  - 1;
		num.pop_back();
		num += tmp;
		cout << num << "\n";
	}
	
    return 0;
}
