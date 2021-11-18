#include<stdio.h>
#include<algorithm>
#include<stack> 
using namespace std;
typedef long long ll;
int N;
ll cnt;

stack<pair<int,int>> st;

int main(){
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		ll h;
		scanf("%d",&h);
		
		while (!st.empty() && st.top().second < h){
			cnt += st.top().first;
			st.pop();
		}
		if (st.empty()){
			st.push({1,h});
		}
		else{
			if (st.top().second == h){
				pair<int,int> cur = st.top();
				st.pop();
				
				cnt += cur.first;
				
				if (!st.empty()){
					cnt++;
				}
                cur.first++;
				st.push({cur.first,cur.second});
				
			}
			else{
				st.push({1,h});
				cnt++;
			}
		}
	}
    
	printf("%lld",cnt);
    return 0;
}

