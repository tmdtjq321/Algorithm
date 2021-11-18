#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
int T, N, M;
int par[200005];

int find(int x){
	if (par[x] == x){
		return x;
	}	
	
	return par[x] = find(par[x]);
}

int main() {
    scanf("%d",&T);
    while(T--){
    	string input1, input2;
    	vector<pair<string,string>> v;
    	map<string, int> s;
    	vector<int> level;
    	memset(par,0,sizeof(par));
    	int cnt = 0;
    	scanf("%d",&N);
    	for (int i = 1; i <= N; i++){
    		cin >> input1 >> input2;
    		v.push_back({input1,input2});
    		if (s.find(input1) == s.end()){
    			s[input1] = cnt;
                cnt++;
			}
			if (s.find(input2) == s.end()){
    			s[input2] = cnt;
                cnt++;
			}
			
		}
		
		for (int i = 0; i < s.size(); i++){
			par[i] = i;
			level.push_back(1);
		}
		
		for (int i = 0; i < v.size(); i++){
			int start = find(s[v[i].first]);
			int end = find(s[v[i].second]);
			
			if (start != end){
				par[end] = start;
				level[start] += level[end];
				level[end] = 1;
				printf("%d\n",level[start]);
			}
			else{
				printf("%d\n",level[end]);
			}
		}	
		
    }
    
    return 0;
}
