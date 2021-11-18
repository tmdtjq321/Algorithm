#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
  int f, t, w; //f -> t w��ŭ�� ����� �Ҹ�ȴ�.
};
vector<node> arr;
int chk[10002]; //��尡 MST�� ������ �Ǿ��ִ��� Ȯ��
int res;
bool cmp(node A, node B){
  return A.w<B.w;
}
int find(int x){
  if(x == chk[x]) return x;
  return chk[x] = find(chk[x]);
}
int main(){
  int v,e;
  scanf("%d%d",&v,&e); //v - ����� ����, e - ������ ����
  for(int i=1;i<=v;i++) chk[i] = i; //Union Find �ʱ�ȭ
  for(int i=0;i<e;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    arr.push_back({a,b,c});
  }
  //ũ�罺Į ������ ���� ���� ����
  sort(arr.begin(),arr.end(),cmp);
  //���Ͼ� ���ε带 ���ؼ� ����Ŭ ã��
  for(int i=0;i<e;i++){
    int pre = find(arr[i].f);//��� ���
    int next = find(arr[i].t);//���� ���
    if(pre == next) continue;
    chk[pre] = next;
    res+=arr[i].w;
  }
  printf("%d",res);
  return 0;
}
