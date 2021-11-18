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
//	//���� P�̳��� �Ÿ��� �� �� �ִµ� �����Ҹ� �ּҷ� �������� L
//	// �ѹ� �̵��� �� �ִ�Ÿ� 
//	int ocnt = 0;
//	for (int i = 0; i <= N; i++){
//		printf("%d\n",i);
//		if (sum + P >= L){ 
//			break;
//		}
//		while (ocnt < N && oil[ocnt].first <= P + sum){
//			dis.push(oil[ocnt]);	// �̵� �Ÿ� ,��� ���� 
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
 
    int ans = 0; // ����
    int here = 0; // ���� ��ġ
 
    for (int i = 0; i < v.size(); i++) {        
 
        // ���� ��ġ(here)���� �⸧�� ���������� �� ���ٸ�
        while (!pq.empty() && here + oil < v[i].first)
        {
            // �켱���� ť�� ����� �⸧���� ������
            printf("oil %d\n",oil);
            oil += pq.top();
            ++ans;
            pq.pop();
        }
 
        // �̵��� ���� �Ÿ���ŭ �⸧�� ���.
        oil = oil - (v[i].first - here);
 
        if (oil < 0) {
            /*
            oil�� ������� ���� ���ݱ��� �������鼭 ������ �⸧����
            �� �Ծ������� �ұ��ϰ� ���� ��ġ(here)���� ������ �� ���ٴ� ��.
            '<='�� �ƴ� ������ '�� �°�' �����ߴٴ� ������ �Ŀ� ���� �� �ִ� �⸧�� �����ؾ���.
            */
            break;
        }
 
        here = v[i].first;
        pq.push(v[i].second); 
		printf("here %d,%d\n",here,oil);   
    }
 	printf("cal\n");
    // ������ ���
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

