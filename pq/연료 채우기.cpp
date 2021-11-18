//#include<stdio.h>
//#include<queue>
//#include<algorithm>
//using namespace std;
//int N, L, P;
//int sum, cnt;
//pair<int, int> oil[10005];
//priority_queue<pair<int,int>> dis;
//
//
//int main() {
//	scanf("%d",&N);
//	for (int i = 0; i <= N; i++){
//		int a, b;
//		scanf("%d%d",&a,&b);
//		oil[i].first = a;
//		oil[i].second = b;
//		if (i == N){
//			L = oil[i].first;
//			P = oil[i].second;
//		}
//	}
//	
//	sort(oil,oil+N);
//	for (int i = 0; i < N; i++){
//		printf("%d %d\n",oil[i].first,oil[i].second);
//	}
//	//현재 P이내의 거리로 갈 수 있는데 주유소를 최소로 목적지는 L
//	// 한번 이동할 때 최대거리 
//	int ocnt = 0;
//	for (int i = 0; i <= N; i++){
//		printf("%d\n",i);
//		if (sum + P >= L){ 
//			break;
//		}
//		while (ocnt < N && oil[ocnt].first <= P + sum){
//			dis.push(oil[ocnt]);	// 이동 거리 ,얻는 연료 
//            printf("push %d %d\n",oil[ocnt].first,oil[ocnt].second);
//			ocnt++;
//		}
//		if (!dis.empty() && sum < dis.top().first){
//			P -= dis.top().first - sum;
//			P += dis.top().second ;
//			sum = dis.top().first;
//			printf("choose : %d %d\n",dis.top().first,dis.top().second);
//			printf("now : %d %d\n",sum,P);
//			dis.pop();
//			cnt++;
//		}
//		if (ocnt == N && sum + P < L){
//			printf("%d\n",sum + P);
//			P = oil[N].second + dis.top().second - dis.top().first;
//			sum = dis.top().first;
//			ocnt = dis.size();
//			cnt = dis.size();
//		}
//	}
//	
//	if (sum + P >= L){ 
//		printf("%d",cnt);
//	}
//	else{
//		printf("-1");
//	}
//	return 0;
//}
#include <bits/stdc++.h>
 
using namespace std;
 
int n, End, oil;
vector<pair<int, int> > v;
priority_queue<int> pq;
 
int main()
{
    scanf("%d", &n);
 
    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        v.push_back({ a, b });
    }
 
    sort(v.begin(), v.end());
 
    scanf("%d %d", &End, &oil);
 
    int ans = 0; // 정답
    int here = 0; // 현재 위치
 
    for (int i = 0; i < v.size(); i++) {        
 
        // 현재 위치(here)에서 기름울 충전했음도 못 간다면
        while (!pq.empty() && here + oil < v[i].first)
        {
            // 우선순위 큐에 저장된 기름들을 꺼낸다
            printf("oil %d\n",oil);
            oil += pq.top();
            ++ans;
            pq.pop();
        }
 
        // 이동할 때도 거리만큼 기름을 사용.
        oil = oil - (v[i].first - here);
 
        if (oil < 0) {
            /*
            oil이 음수라는 것은 지금까지 지나오면서 저장한 기름들을
            다 먹었음에도 불구하고 현재 위치(here)에서 도달할 수 없다는 뜻.
            '<='이 아닌 이유는 '딱 맞게' 도착했다는 뜻으로 후에 먹을 수 있는 기름을 저장해야함.
            */
            break;
        }
 
        here = v[i].first;
        pq.push(v[i].second); 
		printf("here %d,%d\n",here,oil);   
    }
 	printf("cal\n");
    // 나머지 계산
    while (!pq.empty() && here + oil < End)
    {
        oil += pq.top();
        printf("oil %d\n",oil);
        ++ans;
        pq.pop();
    }
 	
 	if (here + oil >= End){
 		printf("%d",ans);	
	}
	else{
		printf("-1");
	}
 
    return 0;
}

