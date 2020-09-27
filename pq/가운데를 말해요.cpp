#include<stdio.h>
#include<queue>
using namespace std;
int N, ncnt;
int num[100005]; 
priority_queue<int> pq;		// �ִ� 
priority_queue<int, vector<int>, greater<int> > min_pq; // �ּ� 

// �ִ����� top�� �ּ����� top���� �׻� �۴�.
int main() {
	scanf("%d",&N); 
	for (int i = 0; i < N; i++){
		int t;
		scanf("%d",&t);
		if (pq.size() == min_pq.size() || pq.size() - min_pq.size() == 1){	
			if (pq.size() == min_pq.size()){ 	// �ִ��� �ּ��� ����� ������ �ִ��� ���� 
				if (pq.size() == 0){
					pq.push(t);
				}
				else{
					if (min_pq.top() < t){
						pq.push(min_pq.top());
						min_pq.pop();
						min_pq.push(t);
					}
					else{
						pq.push(t);
					}
				}
			}
			if (pq.size() - min_pq.size() == 1){	// �ִ����� �ּ������� 1��ŭ ũ�� 
				if (min_pq.size() == 0){
					min_pq.push(t);
				}
				else {
					if (pq.top() >= t){
						min_pq.push(pq.top());
						pq.pop();
						pq.push(t);
					}
					else{
						min_pq.push(t);
					}
				}
			}
		}
		printf("%d\n",pq.top()); 
	}
	return 0;
}
