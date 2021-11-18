#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 300005
using namespace std;
const int MOD = 1e9+7;
typedef long long ll;
struct Line{
    ll A, B, C;
    Line(): Line(1, 1, 1){}
    Line(ll a, ll b, ll c): A(a), B(b), C(c){}
  bool operator<(const Line &x)const{
    return (A*x.B) > (B*x.A); //���� �������� ����
  }
};
//H - Horizontal , x�࿡ ����
//V - Vertial, y�࿡ ����
vector<Line> L, H, V;
int g[MAX] = {0}, gcnt[MAX] = {1}, gsum[MAX] = {0}, G = 0;
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a < 0){ a *= -1; b *= -1; c *= -1; }	// a�� ��� 
        if(a == 0) H.push_back(Line(a, b, c)); // x�࿡ ������ ���� 
        else if(b == 0) V.push_back(Line(a, b, c));	// y�࿡ ������ ���� 
        else L.push_back(Line(a, b, c));
    }
    sort(L.begin(), L.end()); // �������� ���� ����  
    for (int i = 0; i < L.size(); i++){
    	printf("(%lld %lld %lld) ",L[i].A,L[i].B,L[i].C);
	}
	printf("\n");
    auto it = L.begin();
    for(; it  != L.end(); it++){	//B�� ���� �����̸� �����.
    	if(it->B > 0) { // ���Ⱑ ���� 
    		break;	
		}
	}
    L.insert(it, V.begin(), V.end()); //����ġ�� y�࿡ ������ ���� ����.
    L.insert(L.begin(), H.begin(), H.end()); //ó���� x�࿡ ������ ���� ����.
    for (int i = 0; i < L.size(); i++){
    	printf("(%lld %lld %lld) ",L[i].A,L[i].B,L[i].C);
	}
	printf("\n");
    for(int i=1; i<N; i++){
        Line &L1 = L[i-1], &L2 = L[i];
        if(L1.A*L2.B == L1.B*L2.A && L1.B*L2.C == L1.C*L2.B && L1.A*L2.C == L1.C*L2.A) {
        	continue;
		}
        if(L1.A*L2.B != L1.B*L2.A) {
			G++;
		}
        g[i] = G;
        gcnt[g[i]]++;
    }
    for (int i = 0; i < N; i++){
    	printf("%d ",g[i]);
	}
	printf("\n");
	G++;
	for (int i = 0; i < G; i++){
    	printf("%d ",gcnt[i]);
	}
	printf("\n");
    
    for(int i=0; i<G; i++){
    	gsum[i+1] = gsum[i] + gcnt[i]; //dp�̿�
	}
	for (int i = 0; i < G+1; i++){
    	printf("%d ",gsum[i]);
	}
	printf("\n");
    int result = 0;
    for(int i = 0; i < N; i++){
        int gn = g[i];
        if(gn == 0 || gn == G-1) {
        	continue;
		}
        result = (1LL*gsum[gn]*(gsum[G]-gsum[gn+1]) + result) % MOD;
        printf("result %d\n",result);
    }
    printf("%d\n", result);
}
