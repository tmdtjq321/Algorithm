#include<stdio.h>
#include<algorithm>
#include<stack>
#include<vector> 
using namespace std;
typedef long long ll;
int N;

ll max(ll a, ll b){
	return a > b ? a : b;
}

int main(){
	while(1){
		scanf("%d",&N);
		if (N == 0){
			break;
		}
		stack<ll> st;
		vector<ll> v;
		
		ll h, max_num = 0;
		for(int i = 0; i < N; i++){
			scanf("%lld",&h);
			v.push_back(h);
		}
		
		for (int i = 0; i < N; i++){
			while(!st.empty() && v[i] < v[st.top()]){
				ll height = v[st.top()];
				st.pop();
				ll width = i;
				if (!st.empty()){
					width = i - st.top() - 1;
				}
				ll sum = height * width;
				max_num = max(max_num,sum);
			}
			st.push(i);
		}
		ll height, width;
		while(!st.empty()){
			height = v[st.top()];
			st.pop();
			width = N;
			if (!st.empty()){
				width = N - st.top() - 1;
			}
			ll sum = height * width;
			max_num = max(max_num,sum); 
		}
		printf("%lld\n",max_num);
	}
    return 0;
}

